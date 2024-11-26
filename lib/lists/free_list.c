/*
** EPITECH PROJECT, 2024
** C-lists_lib
** File description:
** free_list.c
*/

#include "my_lists.h"

/*
** Frees the list and its data using the function pointer passed as parameter
*/
void free_list(list_t **list, void (*free_data)(void *data))
{
    list_t *tmp = *list;
    list_t *next;

    while (tmp) {
        next = tmp->next;
        if (free_data != NULL)
            free_data(tmp->data);
        free(tmp);
        tmp = next;
    }
    *list = NULL;
}
