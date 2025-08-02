#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Create a new node
Node* createNode(int value){
  Node* newNode = (Node*) malloc(sizeof(Node));
  if(newNode == NULL){
    printf("Memory allocation failed\n");
    exit(1);
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

// Insert a node at the end
void insertAtEnd(Node** headRef, int value){
  Node* newNode = createNode(value);
  if(*headRef == NULL){
    *headRef = newNode;
    return;
  }
  
  Node* current = *headRef;
  while(current->next != NULL){
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

int main(){
  Node* head = NULL;

  // opens the file in read mode
  FILE* file = fopen("random_numbers.txt", "r");
  int value;

  // read integers from file until EOF
  while(fscanf(file, "%d", &value) == 1){
    insertAtEnd(&head, value);
  }

  fclose(file);

  printf("Linked list from the file: ");
  printList(head);

  freeList(head);
  return 0;
}
