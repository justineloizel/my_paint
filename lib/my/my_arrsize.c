/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** my_arrsize
*/

int my_arrsize(char const **arr)
{
    int count = 0;
    for (; arr[count]; count++);
    return count;
}
