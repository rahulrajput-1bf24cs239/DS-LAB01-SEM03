#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top, int* poppedVal) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        *poppedVal = -1;
        return top;
    }
    struct Node* temp = top;
    *poppedVal = temp->data;
    top = top->next;
    free(temp);
    return top;
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}


struct Node* enqueue(struct Node* rear, struct Node** front, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*front == NULL) {
        *front = newNode;
        return newNode;
    }

    rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node* front, struct Node** rear, int* value) {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        *value = -1;
        return front;
    }

    struct Node* temp = front;
    *value = temp->data;
    front = front->next;

    if (front == NULL)
        *rear = NULL;

    free(temp);
    return front;
}

void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *stackTop = NULL;
    struct Node *front = NULL, *rear = NULL;
    int choice, value;

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Push (Stack)\n2. Pop (Stack)\n3. Display Stack\n");
        printf("4. Enqueue (Queue)\n5. Dequeue (Queue)\n6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                stackTop = push(stackTop, value);
                break;

            case 2:
                stackTop = pop(stackTop, &value);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                displayStack(stackTop);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                rear = enqueue(rear, &front, value);
                break;

            case 5:
                front = dequeue(front, &rear, &value);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;

            case 6:
                displayQueue(front);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
