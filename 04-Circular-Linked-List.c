#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert at beginning
void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted at end.\n");
}

// Insert at a specific position
void insertPosition(int value, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertBeginning(value);
        return;
    }

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = last->next;

    for (int i = 1; i < position - 1 && temp != last; i++) {
        temp = temp->next;
    }

    if (temp == last && position > 2) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == last)
        last = newNode;

    printf("Node inserted at position %d.\n", position);
}

// Delete from beginning
void deleteBeginning() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *first = last->next;

    if (first == last) {
        free(first);
        last = NULL;
    } else {
        last->next = first->next;
        free(first);
    }

    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteEnd() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    if (temp == last) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }

    printf("Node deleted from end.\n");
}

// Delete from a specific position
void deletePosition(int position) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteBeginning();
        return;
    }

    struct Node *temp = last->next;

    for (int i = 1; i < position - 1 && temp->next != last->next; i++) {
        temp = temp->next;
    }

    if (temp->next == last->next) {
        printf("Position out of range.\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;

    if (del == last)
        last = temp;

    free(del);

    printf("Node deleted from position %d.\n", position);
}

// Display the list
void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

// Search an element
void search(int value) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;
    int position = 1;

    do {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, position);
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != last->next);

    printf("%d not found in the list.\n", value);
}

// Main function
int main() {
    int choice, value, position;

    do {
        printf("\n===== CIRCULAR LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(value, position);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deletePosition(position);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 9:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}