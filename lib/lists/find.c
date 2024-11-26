/*
** EPITECH PROJECT, 2024
** C-lists_lib
** File description:
** find.c
*/

#include "my_lists.h"

/*
**  Finds a node in the list with the given reference
*/
list_t *find_node(list_t *list, void *ref,
    int (*cmp)(void *data, void *ref))
{
    while (list) {
        if (cmp(list->data, ref) == 0)
            return list;
        list = list->next;
    }
    dprintf(2, "Error: no node found\n");
    return NULL;
}
