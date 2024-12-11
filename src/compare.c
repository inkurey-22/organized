/*
** EPITECH PROJECT, 2024
** organized
** File description:
** compare
*/

#include "my_strings.h"

#include "shell.h"

int compare_by_type(void const *data1, void const *data2)
{
    device_t *device1 = (device_t *)data1;
    device_t *device2 = (device_t *)data2;

    return my_strcmp(device1->type, device2->type);
}

int compare_by_id(void const *data1, void const *data2)
{
    device_t *device1 = (device_t *)data1;
    device_t *device2 = (device_t *)data2;

    return (device1->id - device2->id);
}

int compare_by_name(void const *data1, void const *data2)
{
    device_t *device1 = (device_t *)data1;
    device_t *device2 = (device_t *)data2;

    return my_strcmp(device1->name, device2->name);
}
