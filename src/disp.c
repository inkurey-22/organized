/*
** EPITECH PROJECT, 2024
** organized
** File description:
** disp
*/

#include "my_lists.h"
#include "my_printf.h"

#include "shell.h"

int disp(void *data, __attribute__((unused)) char **args)
{
    list_t *tmp = *(list_t **)data;
    device_t *dev = NULL;

    while (tmp != NULL) {
        dev = tmp->data;
        my_printf("%s n°%i - \"%s\"\n", dev->type, dev->id, dev->name);
        tmp = tmp->next;
    }
    return 0;
}
