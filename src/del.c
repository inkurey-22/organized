/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del
*/

#include <stddef.h>

#include "my_lists.h"
#include "my_printf.h"
#include "my_strings.h"
#include "my_numbers.h"

#include "shell.h"

void free_device(void *data)
{
    device_t *device = (device_t *)data;

    my_printf("%s n°%d - \"%s\" deleted.\n", device->type, device->id,
        device->name);
    free(device->name);
    free(device->type);
    free(device);
}

void delete_first_node(list_t **list, list_t *node, int *status)
{
    *list = node->next;
    free_device(node->data);
    free(node);
    *status = 1;
}

void delete_middle_node(list_t *prev, list_t *node, int *status)
{
    prev->next = node->next;
    free_device(node->data);
    free(node);
    *status = 1;
}

void del_node(list_t **list, int id, int *status)
{
    list_t *tmp = *list;
    list_t *prev = NULL;

    *status = 0;
    if (tmp == NULL)
        return;
    if (((device_t *)tmp->data)->id == id) {
        delete_first_node(list, tmp, status);
        return;
    }
    while (tmp && ((device_t *)tmp->data)->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp != NULL)
        delete_middle_node(prev, tmp, status);
}

int del(void *data, char **args)
{
    int ref = 0;
    int status = 0;

    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i] == NULL || my_str_isnum(args[i]) == 0)
            return 84;
        ref = my_getnbr(args[i]);
        del_node(data, ref, &status);
        if (status == 0)
            return 84;
    }
    return 0;
}
