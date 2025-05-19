/*
** EPITECH PROJECT, 2025
** B-CPE-200-REN-2-1-corewar-enzo.iffis
** File description:
** test_raylib
*/
#include "corewar.h"
#include "corewar_bonus.h"

Color get_champion_color(int color_id)
{
    Color colors[MAX_CHAMP_COLORS] = {
        (Color){0, 102, 204, 255},
        (Color){204, 0, 0, 255},
        (Color){0, 153, 51, 255},
        (Color){255, 204, 0, 255}
    };
    return colors[color_id % MAX_CHAMP_COLORS];
}

int get_memory_owner(arena_t *arena, int position)
{
    int owner = 0;
    int start;
    int end;
    process_list_t *current = arena->process;

    while (current != NULL) {
        if (current->pc == position)
            return current->owner_id;
        current = current->next;
    }
    for (int i = 0; i < arena->nb_champ; i++) {
        start = arena->champ_tab[i].pc_start;
        end = start + arena->champ_tab[i].header.prog_size;
        if (position >= start && position < end)
            return arena->champ_tab[i].id;
    }
    return owner;
}

void draw_arena(arena_t *arena)
{
    int cols = 96;
    int cell_width = 18;
    int cell_height = 10;
    int padding = 2;
    int top_offset = 240;
    int owner;
    int x;
    int y;
    bool this_is_pc;
    Color color;

    for (int i = 0; i < MEM_SIZE; i++) {
        x = (i % cols) * (cell_width + padding);
        y = top_offset + (i / cols) * (cell_height + padding);
        this_is_pc = false;
        process_list_t *current = arena->process;
        while (current != NULL) {
            if (current->pc == i) {
                this_is_pc = true;
                break;
            }
            current = current->next;
        }
        if (this_is_pc)
            color = WHITE;
        else {
            color = DARKGRAY;
            if (arena->arena[i] != 0) {
                owner = get_memory_owner(arena, i);
                if (owner > 0 && owner <= arena->nb_champ)
                    color = get_champion_color(owner - 1);
                 else
                    color = GRAY;
            }
        }
        DrawRectangle(x, y, cell_width, cell_height, color);
    }
}

void draw_champ_name(arena_t *arena) 
{
    int x = 50;
    Color champ_color;

    for (int i = 0; i < arena->nb_champ; i++){
        champ_color = get_champion_color(i);
        DrawText(arena->champ_tab[i].header.prog_name, x, 50, 30, champ_color);
        x += 550;
    }
}

void draw_live_state(arena_t *arena)
{
    Color alive = GREEN;
    Color dead = RED;
    Color champ_color;
    int height = 30;
    int width = 30;
    int x = 50;
    int rect_pos = 180;
    
    for (int i = 0; i < arena->nb_champ; i++){
        champ_color = get_champion_color(i);
        DrawText(TextFormat("Live state :"), x, 110, 20, champ_color);
        if (arena->champ_tab[i].is_alive == true)
            DrawRectangle(rect_pos, 110, width, height, alive);
        else
            DrawRectangle(rect_pos, 110, width, height, dead);
        x += 550;
        rect_pos += 550;
    }
}

void draw_nb_process(arena_t *arena)
{
    int x = 50;

    for (int i = 0; i < arena->nb_champ; i++){
        DrawText(TextFormat("nb of process : %d", arena->champ_tab[i].nb_process), x, 85, 20, RAYWHITE);
        x += 550;
    }
}

void draw_cycles(arena_t *arena)
{
    DrawText(TextFormat("Cycle to die: %d", arena->count_cycle_to_die), 250, 200, 20, RAYWHITE);
    DrawText(TextFormat("/ %d", arena->cycle_to_die), 435, 200, 20, RAYWHITE);
    DrawText(TextFormat("Total cycle : %d", arena->count_cycles), 1000, 200, 20, RAYWHITE);
    DrawText(TextFormat("Nb Live: %d", arena->nb_live), 1450, 200, 20, RAYWHITE);
    DrawText(TextFormat("    / %d", NBR_LIVE), 1565, 200, 20, RAYWHITE);
}

void launch_visualizer(arena_t *arena) 
{
    bool paused = false;

    InitWindow(1920, 1080, "Corewar");
    SetTargetFPS(60);
    load_champions(arena);
    while (!WindowShouldClose() && !arena->game_is_over) {
        if (IsKeyPressed(KEY_SPACE)) {
            paused = !paused;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        draw_arena(arena);
        draw_champ_name(arena);
        draw_live_state(arena);
        draw_nb_process(arena);
        draw_cycles(arena);
        EndDrawing();
        if (paused){
            DrawRectangle(0, 0, 200, 40, BLACK);
            DrawText("PAUSED", 20, 10, 30, RED);
        }
        if (!paused){
            cycle_processes(arena);
            update_cycle(arena);
            if (arena->count_cycle_to_die >= arena->cycle_to_die)
                cycle_to_die_reached(arena);
            if (should_end_game(arena)) {
                arena->game_is_over = true;
                print_winner(arena);
            }
            if (arena->count_cycles == arena->dump_cycles)
                dump_arena(arena);
        }
    }
    CloseWindow();
}
