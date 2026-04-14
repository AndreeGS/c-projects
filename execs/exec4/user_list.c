#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_list.h"

UserList* create_user_list(size_t capacity)
{
    UserList* list = malloc(sizeof(UserList));
    if (!list) return NULL;

    list->data = malloc(sizeof(User*) * capacity);
    if (!list->data) {
        free(list);
        return NULL;
    }

    list->size = 0;
    list->capacity = capacity;

    return list;
}

void destroy_user_list(UserList* list)
{
    if (!list) return;

    for (size_t i = 0; i < list->size; i++) {
        destroy_user(list->data[i]);
    }

    free(list->data);
    free(list);
}

int add_user(UserList* list, User* user)
{
    if (list->size == list->capacity) {

        size_t new_capacity = list->capacity * 2;

        User** temp = realloc(
            list->data,
            new_capacity * sizeof(User*)
        );

        if (!temp) return 0;

        list->data = temp;
        list->capacity = new_capacity;
    }

    list->data[list->size++] = user;
    return 1;
}

User* find_user_by_id(UserList* list, const char* id)
{
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->data[i]->id, id) == 0)
            return list->data[i];
    }
    return NULL;
}

int remove_user_by_id(UserList* list, const char* id)
{
    for (size_t i = 0; i < list->size; i++) {

        if (strcmp(list->data[i]->id, id) == 0) {

            destroy_user(list->data[i]);

            for (size_t j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j + 1];
            }

            list->size--;
            return 1;
        }
    }
    return 0;
}

void print_all_users(const UserList* list)
{
    for (size_t i = 0; i < list->size; i++) {
        print_user(list->data[i]);
    }
}