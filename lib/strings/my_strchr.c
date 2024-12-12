/*
** EPITECH PROJECT, 2024
** bsmyls
** File description:
** my_strrchr
*/

#include <stddef.h>
#include "my_strings.h"

char *my_strchr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (&str[i]);
    }
    return NULL;
}

char *my_strrchr(char *str, char c)
{
    for (int i = my_strlen(str); i >= 0; i--) {
        if (str[i] == c)
            return (&str[i]);
    }
    return NULL;
}
