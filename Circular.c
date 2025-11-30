#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;


void add(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Circular Queue Overflow!\n");
        return;
    }

    if (front == -1)  
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
    printf("%d added to Circular Queue\n", x);
}


void delete() {
    if (front == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("%d deleted from Circular Queue\n", cq[front]);

    if (front == rear)  
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                add(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
