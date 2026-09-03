#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to insert at first
void insertFirst()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted at first.\n");
}

// Function to insert at last
void insertLast()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted at last.\n");
}

// Function to insert at given position
void insertPosition()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertFirst();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position does not exist.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

// Function to delete first node
void deleteFirst()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted.\n");
}

// Function to delete last node
void deleteLast()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // If there is only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

// Function to delete node at given position
void deletePosition()
{
    struct node *temp, *delnode;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        deleteFirst();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position does not exist.\n");
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;

    free(delnode);

    printf("Node at position %d deleted.\n", pos);
}

// Function to traverse/display the list
void traverse()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n========== SINGLY LINEAR LINKED LIST ==========\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Given Position\n");
        printf("4. Delete from First\n");
        printf("5. Delete from Last\n");
        printf("6. Delete from Given Position\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("===============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFirst();
                break;

            case 2:
                insertLast();
                break;

            case 3:
                insertPosition();
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                deletePosition();
                break;

            case 7:
                traverse();
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
