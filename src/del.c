/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del
*/

#include <stddef.h>

#include "my_lists.h"
#include "my_printf.h"
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

void del_node(list_t **list, int id)
{
    list_t *tmp = *list;
    list_t *prev = NULL;

    if (tmp == NULL)
        return;
    if (((device_t *)tmp->data)->id == id) {
        *list = tmp->next;
        free_device(tmp->data);
        free(tmp);
        return;
    }
    while (tmp && ((device_t *)tmp->data)->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free_device(tmp->data);
    free(tmp);
}

int del(void *data, char **args)
{
    int ref = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (args[i] == NULL)
            return 84;
        ref = my_getnbr(args[i]);
        del_node(data, ref);
    }
}
