#ifndef TASKS_H
#define TASKS_H

typedef struct {
    char **items;
    int count;
    int capacity;
} TaskList;

void init_tasks(TaskList *list);
void add_task(TaskList *list);
void view_tasks(TaskList *list);
void free_tasks(TaskList *list);
void delete_task(TaskList *list);

#endif
