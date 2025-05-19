/*
** EPITECH PROJECT, 2024
** my swap
** File description:
** swap two adresses of number
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
