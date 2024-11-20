#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display the linked list
void displayList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sort the linked list
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    struct Node* i;
    struct Node* j;
    for (i = *head; i->next; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Concatenate two linked lists
void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = *head2;
}

// Stack
void push(struct Node** stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

int pop(struct Node** stack) {
    if (*stack == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int data = (*stack)->data;
    struct Node* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

// Queue
void enqueue(struct Node** queue, int data) {
    insertEnd(queue, data);
}

int dequeue(struct Node** queue) {
    if (*queue == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = (*queue)->data;
    struct Node* temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return data;
}

// display the stack
void displayStack(struct Node* stack) {
    if (stack == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (stack) {
        printf("\n%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// display the queue
void displayQueue(struct Node* queue) {
    if (queue == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (queue) {
        printf("%d ", queue->data);
        queue = queue->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* stack = NULL;
    struct Node* queue = NULL;

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1) Insert into Linked List\n");
        printf("2) Display Linked List\n");
        printf("3) Sort Linked List\n");
        printf("4) Reverse Linked List\n");
        printf("5) Concatenate Two Linked Lists\n");
        printf("6) Push to Stack\n");
        printf("7) Pop from Stack\n");
        printf("8) Enqueue to Queue\n");
        printf("9) Dequeue from Queue\n");
        printf("10) Display Stack\n");
        printf("11) Display Queue\n");
        printf("12) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into Linked List: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;
            case 2:
                printf("Linked List: ");
                displayList(list1);
                break;
            case 3:
                sortList(&list1);
                printf("Linked List sorted.\n");
                break;
            case 4:
                reverseList(&list1);
                printf("Linked List reversed.\n");
                break;
            case 5:
                printf("Enter values for the second list (terminate with -1):\n");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    insertEnd(&list2, value);
                }
                concatenateLists(&list1, &list2);
                printf("Lists concatenated.\n");
                break;
            case 6:
                printf("Enter value to push onto Stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 7:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped from Stack: %d\n", value);
                }
                break;
            case 8:
                printf("Enter value to enqueue to Queue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 9:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued from Queue: %d\n", value);
                }
                break;
            case 10:
                displayStack(stack);
                break;
            case 11:
                displayQueue(queue);
                break;
            case 12:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 1
Enter value to insert into Linked List: 1

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 1
Enter value to insert into Linked List: 7

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 1
Enter value to insert into Linked List: 3

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 1
Enter value to insert into Linked List: 0

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 1
Enter value to insert into Linked List: 8

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 2
Linked List: 1 -> 7 -> 3 -> 0 -> 8 -> NULL

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 3
Linked List sorted.

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 2
Linked List: 0 -> 1 -> 3 -> 7 -> 8 -> NULL

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 4
Linked List reversed.

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 2
Linked List: 8 -> 7 -> 3 -> 1 -> 0 -> NULL

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 5
Enter values for the second list (terminate with -1):
1
2
3
4
5
-1
Lists concatenated.

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 2
Linked List: 8 -> 7 -> 3 -> 1 -> 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 6
Enter value to push onto Stack: 1

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 6
Enter value to push onto Stack: 2

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 6
Enter value to push onto Stack: 3

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 10
Stack:
3
2
1

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 8
Enter value to enqueue to Queue: 1

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 8
Enter value to enqueue to Queue: 2

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 8
Enter value to enqueue to Queue: 3

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 11
Queue: 1 2 3

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 7
Popped from Stack: 3

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 10
Stack:
2
1

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 9
Dequeued from Queue: 1

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice: 11
Queue: 2 3

Menu:
1) Insert into Linked List
2) Display Linked List
3) Sort Linked List
4) Reverse Linked List
5) Concatenate Two Linked Lists
6) Push to Stack
7) Pop from Stack
8) Enqueue to Queue
9) Dequeue from Queue
10) Display Stack
11) Display Queue
12) Exit
Enter your choice:12
Exiting program.

Process returned 0 (0x0)   execution time : 475.729 s
Press any key to continue.
