#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Insert at the start
void insertAtStart(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }

    printf("%d inserted at start.\n", value);
}

// Insert at the end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("%d inserted at end.\n", value);
}

// Delete from the start
void deleteAtStart() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("%d deleted from start.\n", temp->data);

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

// Delete from the end
void deleteAtEnd() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = tail;
    printf("%d deleted from end.\n", temp->data);

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

// Forward traversal
void forwardTraversal() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Forward Traversal: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Backward traversal
void backwardTraversal() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = tail;

    printf("Backward Traversal: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Start\n");
        printf("4. Delete at End\n");
        printf("5. Forward Traversal\n");
        printf("6. Backward Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtStart(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                deleteAtStart();
                break;

            case 4:
                deleteAtEnd();
                break;

            case 5:
                forwardTraversal();
                break;

            case 6:
                backwardTraversal();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}