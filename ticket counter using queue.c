#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Add customer (Take Ticket)
void enqueue(int ticket) {
    if (rear == MAX - 1) {
        printf("Queue is full! No more tickets.\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = ticket;
    printf("Ticket %d added to queue.\n", ticket);
}

// Serve customer
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! No customers.\n");
        return;
    }

    printf("Serving Ticket %d\n", queue[front]);
    front++;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Customers in queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, ticket = 1;

    while (1) {
        printf("\n--- Ticket Counter System ---\n");
        printf("1. Take Ticket\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(ticket);
                ticket++;
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
