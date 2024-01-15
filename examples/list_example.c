#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_lib.h"

struct user
{
    int id;
    char *name;
};

typedef struct user *User;

User create_user(char *name, int id)
{
    User new_user = (User)malloc(sizeof(struct user));
    new_user->name = strcpy((char *)malloc(sizeof(char) * 30), name);
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

int compare_user(void *u1, void *u2)
{
    return ((User)u1)->id > ((User)u2)->id;
}

int equal_id(void *u, void *id)
{
    return ((User)u)->id == *((int *)id);
}

void *copy_user(void *userp)
{
    const User user = (User)userp;
    return create_user(user->name, (user->id) * -1);
}

void clear()
{
    char c;
    scanf("%c", &c);
    while (c != '\n' && c != '\0')
        scanf("%c", &c);
}

int main(void)
{
    char nameInput[30];
    int idInput;
    int option = 0;
    List users = create_list();

    do
    {
        printf("\n------ MENU ------\n1 - Add new user\n2 - Print list\n3 - Sort\n4 - Sort insert\n5 - Custom clone test\n6 - Search by id\n7 - Remove user\n8 - Exit\n--> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Id: ");
            scanf("%d", &idInput);
            clear();

            printf("Name: ");
            fgets(nameInput, 30, stdin);

            if (nameInput[0] != '\0' && nameInput[strlen(nameInput) - 1] == '\n')
                nameInput[strlen(nameInput) - 1] = '\0';

            append(users, create_user(nameInput, idInput));

            printf("Added %s", nameInput);
            break;
        case 2:
            printf("\n%d users {\n", list_length(users));
            for_each_element(users, print_user);
            printf("}");
            break;
        case 3:
            sort_list(users, compare_user);
            break;
        case 4:
            printf("Id: ");
            scanf("%d", &idInput);
            clear();

            printf("Name: ");
            fgets(nameInput, 30, stdin);

            if (nameInput[0] != '\0' && nameInput[strlen(nameInput) - 1] == '\n')
                nameInput[strlen(nameInput) - 1] = '\0';

            insert_sorted(users, create_user(nameInput, idInput), compare_user);

            break;
        case 5:
            List copy = clone_list_custom_reversed(users, copy_user);
            printf("\n%d Custom users: {\n", list_length(users));
            for_each_element(copy, print_user);
            printf("}");
            free_list_func(copy, free_user);
            break;
        case 6:
            printf("Id: ");
            scanf("%d", &idInput);
            clear();

            Node found_node = find_node(users, equal_id, &idInput);
            if (found_node != NULL)
                print_user(found_node->data);
            else
                printf("User not found!");

            break;
        case 7:
            printf("Id: ");
            scanf("%d", &idInput);
            clear();

            Node found_node2 = find_node(users, equal_id, &idInput);
            if (found_node != NULL)
                remove_node(users, found_node2);
            else
                printf("User not found!\n");
            break;
        case 8:
            List l = find_all_nodes(users, compare_user, create_user("", 6));
            printf("\n%d users found {\n", list_length(l));
            for_each_element(l, print_user);
            printf("}");
            free_list(l);
            break;
        default:
            printf("Enter a valid option!\n");
            break;
        }
    } while (option != 8);

    free_list_func(users, free_user);
    return 0;
}
