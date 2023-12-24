#include "stack.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    int id;
    char *name;
};

typedef struct user *User;

User create_user(char *name, int id)
{
    User new_user = (User)malloc(sizeof(struct user));
    new_user->name = name;
    new_user->id = id;

    return new_user;
}

void free_user(void *data)
{
    free(((User)data)->name);
    free(data);
}

void print_user(void *u)
{
    printf("User { id: %d, name: %s }\n", ((User)u)->id, ((User)u)->name);
}

int main()
{
    char *nameInput;
    int idInput;
    int option = 0;
    List users = create_list();

    do
    {
        printf("------ MENU ------\n1 - Add new user\n2 - Print list\n3 - Exit\n");
        scanf("%d", &option);

        fflush(stdin);

        switch (option)
        {
        case 1:
            nameInput = (char *)malloc(sizeof(char) * 30);
            printf("Id: ");
            scanf("%d", &idInput);
            fflush(stdin);

            printf("Name: ");
            fgets(nameInput, 30, stdin);

            if (strcmp(nameInput, "exit\n") == 0)
                break;

            if (nameInput[0] != '\0' && nameInput[strlen(nameInput) - 1] == '\n')
                nameInput[strlen(nameInput) - 1] = '\0';

            append(users, create_user(nameInput, idInput));

            printf("Added %s\n", nameInput);
            break;
        case 2:
            for_each_element(users, print_user);
            break;
        case 3:
            break;
        default:
            printf("Enter a valid option!");
            break;
        }
    } while (option != 3);

    free_list_func(users, free_user);
    return 0;
}
