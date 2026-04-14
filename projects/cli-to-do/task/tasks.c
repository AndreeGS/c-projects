#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tasks.h"

#define TASK_SIZE 256

void init_tasks(TaskList *list) {
    list->capacity = 10;
    list->count = 0;
    list->items = malloc(list->capacity * sizeof(char *));
}

void add_task(TaskList *list) {
    char buffer[TASK_SIZE];

    printf("Enter task: ");
    getchar();
    fgets(buffer, TASK_SIZE, stdin);

    buffer[strcspn(buffer, "\n")] = 0;

    if (list->count == list->capacity) {
        list->capacity *= 2;
        list->items = realloc(
            list->items,
            list->capacity * sizeof(char *)
        );
    }

    list->items[list->count] = malloc(strlen(buffer) + 1);

    strcpy(list->items[list->count], buffer);

    list->count++;

    printf("Task added!\n");
}

void view_tasks(TaskList *list) {

    printf("+--------------------------------+\n");
    printf("|            LIST APP            |\n");
    for (int i = 0; i < list->count; i++) {
        printf("| %d. %s\n", i + 1, list->items[i]);
    }
    printf("+--------------------------------+\n");
}

void free_tasks(TaskList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->items[i]);
    }
    free(list->items);
}

void delete_task(TaskList *list) {
    int index;

    printf("Enter task number to delete: ");
    if (scanf("%d", &index) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n'); // limpa buffer
        return;
    }

    if (index < 1 || index > list->count) {
        printf("Invalid task number.\n");
        return;
    }

    free(list->items[index - 1]);

    for (int i = index - 1; i < list->count - 1; i++) {
        list->items[i] = list->items[i + 1];
    }

    list->count--;

    printf("Task deleted!\n");
}
