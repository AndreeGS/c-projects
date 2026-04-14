#include <stdio.h>
#include <string.h>
#include "storage.h"

void save_tasks(TaskList *list) {
    FILE *file = fopen("tasks.txt", "w");

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->items[i]);
    }

    fclose(file);
}
