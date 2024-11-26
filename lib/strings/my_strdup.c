/*
** EPITECH PROJECT, 2024
** B-CPE-100-LIL-1-1-cpoolday08-theophile.riffe
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_strings.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (new == NULL)
        return NULL;
    for (; src[i] != '\0'; i++)
        new[i] = src[i];
    new[i] = '\0';
    return new;
}
