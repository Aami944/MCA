#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void delete(int value) {
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void displayForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse(struct Node* node) {
    if (node == NULL) return;
    displayReverse(node->next);
    printf("%d ", node->data);
}

void search(int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display Forward\n4.Display Reverse\n5.Search\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                displayForward();
                break;
            case 4:
                displayReverse(head);
                printf("\n");
                break;
            case 5:
                scanf("%d", &value);
                search(value);
                break;
            case 6:
                exit(0);
        }
    }
}
