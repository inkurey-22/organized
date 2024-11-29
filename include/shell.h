/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

typedef struct device_s {
    char *name;
    char *type;
    int id;
} device_t;

typedef struct sort_crit {
    int (*cmp)(void const *data1, void const *data2);
} sort_crit_t;

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
