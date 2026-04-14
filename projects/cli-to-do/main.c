#include <stdio.h>
#include "task/tasks.h"
#include "storage/storage.h"

void menu();

int main() {
    int choice = 0;
    TaskList tasks;

    init_tasks(&tasks);

    while (choice != 5) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_task(&tasks);
            break;
        case 2:
            view_tasks(&tasks);
            break;
        case 3:
            save_tasks(&tasks);
            break;
        case 4: 
            delete_task(&tasks);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    free_tasks(&tasks);
    return 0;
}

void menu() {
    printf("+--------------------------------+\n");
    printf("|            TODO APP            |\n");
    printf("+--------------------------------+\n");
    printf("| 1. Add task                    |\n");
    printf("| 2. View tasks                  |\n");
    printf("| 3. Save tasks                  |\n");
    printf("| 4. Delete task                 |\n");
    printf("| 5. Exit                        |\n");
    printf("+--------------------------------+\n");
}
