#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

static char* copy_string(const char* src) {
    char* dest = malloc(strlen(src) + 1);
    if (dest)
        strcpy(dest, src);
    return dest;
}

User* create_user(const char* id,
                  const char* name,
                  const char* email,
                  int age)
{
    User* user = malloc(sizeof(User));
    if (!user) return NULL;

    user->age = age;

    user->id = copy_string(id);
    user->name = copy_string(name);
    user->email = copy_string(email);

    if (!user->id || !user->name || !user->email) {
        destroy_user(user);
        return NULL;
    }

    return user;
}

void destroy_user(User* user)
{
    if (!user) return;

    free(user->id);
    free(user->name);
    free(user->email);
    free(user);
}

void print_user(const User* user)
{
    if (!user) return;

    printf("ID: %s\n", user->id);
    printf("Nome: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Idade: %d\n", user->age);
    printf("------------------------\n");
}