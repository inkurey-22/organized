/*
** EPITECH PROJECT, 2024
** c_lists
** File description:
** lists
*/

#ifndef CLISTS_H
    #define CLISTS_H

    #include <stdlib.h>
    #include <stdio.h>

/*
** The structure, and especially its data
** is just an example. You should modify it
** to fit your needs.
**
** The same applies for the functions below,
** you should modify the comparisons and the
** data type to fit your needs.
*/

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

list_t *create_node(void *);
list_t *reverse_list(list_t *);
list_t *find_node(list_t *, void *,
    int (*cmp)(void *, void *));

int list_size(list_t **);

void add_to_top(list_t **, void *);
void append_node(list_t **, void *);
void free_list(list_t **, void (*free_data)(void *));
void remove_node(list_t **, void *, void (*free_data)(void *),
    int (*cmp)(void *, void *));

#endif
