#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

Person* create_person(const char* name, const int age);
void add_person(Person*** people, int* size, Person* new_person);
void print_people(Person** people, int size);
void free_people(Person** people, int size);

int main() {

    Person** people = NULL;
    int size = 0;

    add_person(&people, &size, create_person("Andre", 28));
    add_person(&people, &size, create_person("Maria", 22));
    add_person(&people, &size, create_person("Joao", 35));

    print_people(people, size);

    free_people(people, size);

    return 0;
}

Person* create_person(const char* name, const int age)
{
    Person* p = malloc(sizeof(Person));
    if (!p) return NULL;

    strcpy(p->name, name);
    p->age = age;

    return p;
}

void add_person(Person*** people, int* size, Person* new_person)
{
    *people = realloc(*people, (*size + 1) * sizeof(Person*));
    if (!*people) exit(1);

    (*people)[*size] = new_person;
    (*size)++;
}

void print_people(Person** people, int size) {
    for (int i = 0; i < size; i++) {
        printf("Nome: %s | Idade: %d\n",
               people[i]->name,
               people[i]->age);
    }
}

void free_people(Person** people, int size) {

    for (int i = 0; i < size; i++) {
        free(people[i]);
    }

    free(people);
}
