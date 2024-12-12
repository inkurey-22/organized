/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort
*/

#include <stddef.h>

#include "my_lists.h"
#include "my_strings.h"

#include "shell.h"

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

static int multi_criteria_cmp(void const *data1, void const *data2,
    sort_crit_t *criteria, int criteria_count)
{
    int result = 0;

    for (int i = 0; i < criteria_count; i++) {
        result = criteria[i].cmp(data1, data2);
        if (criteria[i].reverse) {
            result = -result;
        }
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

static void setup_criteria(int *crit_index, sort_crit_t *crits,
    int (*cmp)(void const *, void const *))
{
    crits[*crit_index].cmp = cmp;
    crits[*crit_index].reverse = 0;
    *crit_index += 1;
}

static int parse_criteria(char **args, sort_crit_t *crits, int crits_nb)
{
    int crit_index = 0;

    for (int i = 0; i < crits_nb; i++) {
        if (my_strcmp(args[i], "TYPE") == 0)
            setup_criteria(&crit_index, crits, &compare_by_type);
        if (my_strcmp(args[i], "ID") == 0)
            setup_criteria(&crit_index, crits, &compare_by_id);
        if (my_strcmp(args[i], "NAME") == 0)
            setup_criteria(&crit_index, crits, &compare_by_name);
        if (my_strcmp(args[i], "-r") == 0 && crit_index > 0)
            crits[crit_index - 1].reverse = 1;
    }
    return crit_index;
}

static int check_crits(char **args)
{
    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i]; i++) {
        if (my_strcmp(args[i], "TYPE") == 0
            || my_strcmp(args[i], "ID") == 0
            || my_strcmp(args[i], "NAME") == 0
            || my_strcmp(args[i], "-r") == 0)
            continue;
        return 84;
    }
    return 0;
}

int sort(void *data, char **args)
{
    list_t **list = (list_t **)data;
    int crits_nb = my_tablen(args);
    sort_crit_t crits[crits_nb];
    int crit_index = parse_criteria(args, crits, crits_nb);

    if (check_crits(args) == 84)
        return 84;
    if (crit_index == 0)
        return 84;
    merge_sort(list, crits, crit_index);
    return 0;
}
