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

int check_args(char **args, int i)
{
    if (args[i] == NULL || args[i + 1] == NULL)
        return 84;
    if (my_strcmp(args[i], "\"\"") == 0 || my_strcmp(args[i + 1], "\"\"") == 0)
        return 84;
    if (my_strcmp(args[i], "WIRE") != 0 && my_strcmp(args[i], "ACTUATOR") != 0
        && my_strcmp(args[i], "DEVICE") != 0 &&
        my_strcmp(args[i], "PROCESSOR") != 0 &&
        my_strcmp(args[i], "SENSOR") != 0)
        return 84;
    return 0;
}

int add(void *data, char **args)
{
    device_t *dev = NULL;
    list_t **tmp = data;

    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i += 2){
        if (check_args(args, i) == 84)
            return 84;
        dev = malloc(sizeof(device_t));
        if (dev == NULL)
            return 84;
        dev->type = my_strdup(args[i]);
        dev->name = my_strdup(args[i + 1]);
        dev->id = (*tmp == NULL) ? 0 : find_id(data) + 1;
        add_to_top(data, dev);
        my_printf("%s n°%i - \"%s\" added.\n", dev->type, dev->id, dev->name);
    }
    return 0;
}
