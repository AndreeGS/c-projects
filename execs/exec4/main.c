#include <stdio.h>
#include "user.h"
#include "user_list.h"

int main()
{
    UserList* list = create_user_list(2);

    add_user(list, create_user("1", "Andre", "andre@email.com", 28));
    add_user(list, create_user("2", "Maria", "maria@email.com", 25));
    add_user(list, create_user("3", "Joao", "joao@email.com", 30));

    printf("=== TODOS USUARIOS ===\n");
    print_all_users(list);

    printf("\n=== BUSCANDO ID 2 ===\n");
    User* found = find_user_by_id(list, "2");
    if (found)
        print_user(found);

    printf("\n=== REMOVENDO ID 2 ===\n");
    remove_user_by_id(list, "2");

    printf("\n=== LISTA FINAL ===\n");
    print_all_users(list);

    destroy_user_list(list);

    return 0;
}