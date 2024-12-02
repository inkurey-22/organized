/*
** EPITECH PROJECT, 2024
** organized
** File description:
** add node
*/

#include <stddef.h>

#include "my_strings.h"
#include "my_lists.h"
#include "my_printf.h"

#include "shell.h"

int find_id(list_t **data)
{
    list_t *tmp = *data;
    device_t *dev = NULL;
    int id = 0;

    while (tmp != NULL){
        dev = tmp->data;
        if (dev->id > id)
            id = dev->id;
        tmp = tmp->next;
    }
    return id;
}

int add(void *data, char **args)
{
    device_t *dev = NULL;
    list_t **tmp = data;

    for (int i = 0; args[i] != NULL; i += 2){
        if (args[i] == NULL || args[i + 1] == NULL)
            return 84;
        dev = malloc(sizeof(device_t));
        if (dev == NULL)
            return 84;
        dev->type = my_strdup(args[i]);
        dev->name = my_strdup(args[i + 1]);
        if (*tmp == NULL)
            dev->id = 0;
        else
            dev->id = find_id(data) + 1;
        add_to_top(data, dev);
        my_printf("%s n°%i - \"%s\" added.\n", dev->type, dev->id, dev->name);
    }
    return 0;
}
