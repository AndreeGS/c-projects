#ifndef USER_LIST_H
#define USER_LIST_H

#include <stddef.h>
#include "user.h"

typedef struct {
    User** data;
    size_t size;
    size_t capacity;
} UserList;

UserList* create_user_list(size_t capacity);

void destroy_user_list(UserList* list);

int add_user(UserList* list, User* user);

User* find_user_by_id(UserList* list, const char* id);

int remove_user_by_id(UserList* list, const char* id);

void print_all_users(const UserList* list);

#endif