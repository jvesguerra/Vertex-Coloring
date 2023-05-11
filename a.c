#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

// Define a struct for the node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create a linked list with three nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Create a new node with a pointer to a new linked list
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 4;
    new_node->next = (struct Node*)malloc(sizeof(struct Node));
    new_node->next->data = 5;
    new_node->next->next = NULL;

    // Insert the new node into the existing linked list
    new_node->next->next = head;
    head = new_node;

    // Print the linked list to verify the new node was inserted at the head
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free the memory allocated for the linked list when you're done with it
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}