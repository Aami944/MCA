#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    if(top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = x;
        printf("%d pushed to stack\n", x);
    }
}

void pop() {
    if(top == -1)
        printf("Stack Underflow!\n");
    else
        printf("%d popped from stack\n", stack[top--]);
}

void displayStack() {
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        if(front == -1)
            front = 0;
        queue[++rear] = x;
        printf("%d inserted in queue\n", x);
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("%d removed from queue\n", queue[front++]);
}

void displayQueue() {
    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, subchoice, value;

    while(1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                while(1) {
                    printf("\n--- STACK MENU ---\n");
                    printf("1. Push\n2. Pop\n3. Display Stack\n4. Back to Main Menu\n");
                    scanf("%d", &subchoice);

                    if(subchoice == 4) break;

                    switch(subchoice) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            push(value);
                            break;
                        case 2:
                            pop();
                            break;
                        case 3:
                            displayStack();
                            break;
                        default:
                            printf("Invalid choice!\n");
                    }
                }
                break;

            case 2:
                while(1) {
                    printf("\n--- QUEUE MENU ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Back to Main Menu\n");
                    scanf("%d", &subchoice);

                    if(subchoice == 4) break;

                    switch(subchoice) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            enqueue(value);
                            break;
                        case 2:
                            dequeue();
                            break;
                        case 3:
                            displayQueue();
                            break;
                        default:
                            printf("Invalid choice!\n");
                    }
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}