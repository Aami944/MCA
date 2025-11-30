#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
}

void insertBack(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertPos(int value, int pos) {
    if (pos == 1) {
        insertFront(value);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) return;
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFront() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void deleteBack() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deletePos(int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        deleteFront();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
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

void displayBackward() {
    struct Node* temp = head;
    if (temp == NULL) return;
    while (temp->next != NULL) temp = temp->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value, pos;
    while (1) {
        printf("\n1.Insert Front\n2.Insert Back\n3.Insert Position\n4.Delete Front\n5.Delete Back\n6.Delete Position\n7.Display Forward\n8.Display Backward\n9.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                scanf("%d", &value);
                insertBack(value);
                break;
            case 3:
                scanf("%d %d", &value, &pos);
                insertPos(value, pos);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteBack();
                break;
            case 6:
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 7:
                displayForward();
                break;
            case 8:
                displayBackward();
                break;
            case 9:
                exit(0);
        }
    }
}