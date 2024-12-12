/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del
*/

#include <stddef.h>
#include <string.h>

#include "my_lists.h"
#include "my_printf.h"
#include "my_strings.h"
#include "my_numbers.h"
#include "shell.h"

int parse_range(const char *arg, int *start, int *end)
{
    char *dash = my_strchr((char *)arg, '-');

    if (dash == NULL)
        return 0;
    *start = my_getnbr(arg);
    *end = my_getnbr(dash + 1);
    return 1;
}

static void free_device(void *data)
{
    device_t *device = (device_t *)data;

    my_printf("%s n°%d - \"%s\" deleted.\n",
        device->type, device->id, device->name);
    free(device->name);
    free(device->type);
    free(device);
}

static void delete_first_node(list_t **list, list_t *node, int *status)
{
    *list = node->next;
    free_device(node->data);
    free(node);
    *status = 1;
}

static void delete_middle_node(list_t *prev, list_t *node, int *status)
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

static int del_single_node(void *data, const char *arg)
{
    int ref = my_getnbr(arg);
    int status = 0;

    del_node((list_t **)data, ref, &status);
    return status;
}

int del_range_nodes(void *data, int start, int end)
{
    int status = 0;

    for (int j = start + 1; j <= end; j++) {
        del_node((list_t **)data, j, &status);
        if (status == 0)
            return 84;
    }
    return 0;
}

int handle_argument(void *data, const char *arg)
{
    int start = 0;
    int end = 0;

    if (parse_range(arg, &start, &end)) {
        return del_range_nodes(data, start, end);
    } else {
        if (my_str_isnum(arg) == 0 || del_single_node(data, arg) == 0)
            return 84;
    }
    return 0;
}

int del(void *data, char **args)
{
    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++)
        if (handle_argument(data, args[i]) == 84)
            return 84;
    return 0;
}
