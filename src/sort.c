/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort
*/

#include "my_strings.h"

#include "my_lists.h"

#include "shell.h"

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

static int compare_by_type(void const *data1, void const *data2)
{
    device_t *device1 = (device_t *)data1;
    device_t *device2 = (device_t *)data2;

    return my_strcmp(device1->type, device2->type);
}

static int compare_by_id(void const *data1, void const *data2)
{
    device_t *device1 = (device_t *)data1;
    device_t *device2 = (device_t *)data2;

    return (device1->id - device2->id);
}

static int compare_by_name(void const *data1, void const *data2)
{
    device_t *device1 = (device_t *)data1;
    device_t *device2 = (device_t *)data2;

    return my_strcmp(device1->name, device2->name);
}

static int multi_criteria_cmp(void const *data1, void const *data2,
    sort_crit_t *criteria, int criteria_count)
{
    int result = 0;

    for (int i = 0; i < criteria_count; i++) {
        result = criteria[i].cmp(data1, data2);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

list_t *sorted_merge(list_t *a, list_t *b,
    sort_crit_t *criteria, int criteria_count)
{
    list_t *result = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (multi_criteria_cmp(a->data, b->data, criteria, criteria_count) <= 0) {
        result = a;
        result->next = sorted_merge(a->next, b, criteria, criteria_count);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next, criteria, criteria_count);
    }
    return result;
}

void split(list_t *src, list_t **front, list_t **back)
{
    list_t *slow = src;
    list_t *fast = src->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = src;
    *back = slow->next;
    slow->next = NULL;
}

void merge_sort(list_t **list, sort_crit_t *criteria, int criteria_count)
{
    list_t *head = *list;
    list_t *a = NULL;
    list_t *b = NULL;

    if (head == NULL || head->next == NULL)
        return;
    split(head, &a, &b);
    merge_sort(&a, criteria, criteria_count);
    merge_sort(&b, criteria, criteria_count);
    *list = sorted_merge(a, b, criteria, criteria_count);
}

int sort(void *data, char **args)
{
    list_t **list = (list_t **)data;
    int crits_nb = my_tablen(args);
    sort_crit_t crits[crits_nb];
    int reverse = 0;

    for (int i = 0; i < crits_nb; i++) {
        if (my_strcmp(args[i], "TYPE") == 0)
            crits[i].cmp = &compare_by_type;
        if (my_strcmp(args[i], "ID") == 0)
            crits[i].cmp = &compare_by_id;
        if (my_strcmp(args[i], "NAME") == 0)
            crits[i].cmp = &compare_by_name;
        if (my_strcmp(args[i], "TYPE") != 0 && my_strcmp(args[i], "ID") != 0
            && my_strcmp(args[i], "NAME") != 0)
            return 84;
    }
    merge_sort(list, crits, crits_nb);
    if (reverse)
        *list = reverse_list(*list);
}
