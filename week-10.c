DFS : 
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int stack[MAX_NODES];
int top = -1;
int nodes;

int DFS(int startNode) {
    int visitedCount = 0;
    stack[++top] = startNode;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            visited[node] = 1;
            visitedCount++;
            for (int i = 0; i < nodes; i++) {
                if (graph[node][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    return visitedCount;
}

int main() {
    int edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v) where u and v are node indices starting from 0:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    int visitedNodes = DFS(0);

    if (visitedNodes == nodes) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}

output - 
Enter the number of nodes: 4
Enter the number of edges: 3
Enter the edges (u v) where u and v are node indices starting from 0:
0 1
1 2
2 3
The graph is connected.

Enter the number of nodes: 5
Enter the number of edges: 3
Enter the edges (u v) where u and v are node indices starting from 0:
0 1
1 2
3 4
The graph is not connected.

HASHING : 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Employee {
    int key;
    char name[50];
    char position[50];
} Employee;

Employee hashTable[TABLE_SIZE];
int isOccupied[TABLE_SIZE];

void insert(int key, const char* name, const char* position) {
    int address = key % TABLE_SIZE;
    while (isOccupied[address]) {
        address = (address + 1) % TABLE_SIZE;
    }
    hashTable[address].key = key;
    strcpy(hashTable[address].name, name);
    strcpy(hashTable[address].position, position);
    isOccupied[address] = 1;
}

Employee* search(int key) {
    int address = key % TABLE_SIZE;
    int startAddress = address;
    while (isOccupied[address]) {
        if (hashTable[address].key == key) {
            return &hashTable[address];
        }
        address = (address + 1) % TABLE_SIZE;
        if (address == startAddress) {
            break;
        }
    }
    return NULL;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (isOccupied[i]) {
            printf("[%02d]: (Key: %d, Name: %s, Position: %s)\n", i, hashTable[i].key, hashTable[i].name, hashTable[i].position);
        } else {
            printf("[%02d]: NULL\n", i);
        }
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        isOccupied[i] = 0;
    }

    int continueInput = 1;
    while (continueInput) {
        int key;
        char name[50], position[50];

        printf("\nEnter employee details:\n");
        printf("Enter key: ");
        scanf("%d", &key);
        getchar();

        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter position: ");
        fgets(position, sizeof(position), stdin);
        position[strcspn(position, "\n")] = '\0';

        insert(key, name, position);

        printf("\nDo you want to add another employee? (1 for yes, 0 for no): ");
        scanf("%d", &continueInput);
        getchar();
    }

    printf("\nHash Table:\n");
    displayHashTable();

    int searchKey;
    printf("\nEnter the key to search for: ");
    scanf("%d", &searchKey);

    Employee* result = search(searchKey);
    if (result != NULL) {
        printf("\nEmployee found: Key: %d, Name: %s, Position: %s\n", result->key, result->name, result->position);
    } else {
        printf("\nEmployee with key %d not found.\n", searchKey);
    }

    return 0;
}

OUTPUT : 
Enter employee details:
Enter key: 1
Enter name: Alice
Enter position: Manager

Do you want to add another employee? (1 for yes, 0 for no): 1

Enter employee details:
Enter key: 2
Enter name: Bob
Enter position: Engineer

Do you want to add another employee? (1 for yes, 0 for no): 1

Enter employee details:
Enter key: 3
Enter name: Charlie
Enter position: Technician

Do you want to add another employee? (1 for yes, 0 for no): 0

Hash Table:
[00]: (Key: 1, Name: Alice, Position: Manager)
[01]: (Key: 2, Name: Bob, Position: Engineer)
[02]: (Key: 3, Name: Charlie, Position: Technician)
[03]: NULL
[04]: NULL
[05]: NULL
[06]: NULL
[07]: NULL
[08]: NULL
[09]: NULL

Enter the key to search for: 2

Employee found: Key: 2, Name: Bob, Position: Engineer

