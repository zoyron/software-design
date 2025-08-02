#include <stdio.h>
#include <stdlib.h>

// Define struct and alias it as "Node"
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertEnd(Node** headRef, int value) {
    Node* newNode = createNode(value);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Print the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the list
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);

    printf("Linked List: ");
    printList(head);

    freeList(head);
    return 0;
}
