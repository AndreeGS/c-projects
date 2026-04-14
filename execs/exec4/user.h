#ifndef USER_H
#define USER_H

typedef struct {
    char *id;
    char *name;
    char *email;
    int age;
} User;

User* create_user(const char* id,
                  const char* name,
                  const char* email,
                  int age);

void destroy_user(User* user);

void print_user(const User* user);

#endif