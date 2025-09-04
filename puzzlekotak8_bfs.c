#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 3

typedef struct Node {
    int puzzle[SIZE][SIZE];
    struct Node* next;
    char move[20];
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int puzzle[SIZE][SIZE], const char* move) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            newNode->puzzle[i][j] = puzzle[i][j];
        }
    }
    strcpy(newNode->move, move);
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int puzzle[SIZE][SIZE], const char* move) {
    Node* newNode = createNode(puzzle, move);
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        return;
    }
    
    Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void printPuzzle(int puzzle[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 0) {
                printf("  ");
            } else {
                printf("%d ", puzzle[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isGoal(int puzzle[SIZE][SIZE], int tujuan[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] != tujuan[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void copyPuzzle(int src[SIZE][SIZE], int dest[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void findEmptyPosition(int puzzle[SIZE][SIZE], int* x, int* y) {
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            if (puzzle[i][j] == 0) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

void generateNewState(int puzzle[SIZE][SIZE], int newPuzzle[SIZE][SIZE], int x, int y, int newX, int newY) {
    copyPuzzle(puzzle, newPuzzle);
    int temp = newPuzzle[x][y];
    newPuzzle[x][y] = newPuzzle[newX][newY];
    newPuzzle[newX][newY] = temp;
}

bool isVisited(int puzzle[SIZE][SIZE], Queue* visited) {
    Node* current = visited->front;
    while (current != NULL) {
        bool match = true;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (current->puzzle[i][j] != puzzle[i][j]) {
                    match = false;
                    break;
                }
            }
            if (!match) break;
        }
        if (match) return true;
        current = current->next;
    }
    return false;
}

void solvePuzzle(int awal[SIZE][SIZE], int tujuan[SIZE][SIZE]) {
    Queue* q = createQueue();
    Queue* visited = createQueue();
    
    enqueue(q, awal, "Kondisi awal");
    enqueue(visited, awal, "");
    
    int step = 0;
    
    while (!isEmpty(q)) {
        int current[SIZE][SIZE];
        copyPuzzle(q->front->puzzle, current);
        char move[20];
        strcpy(move, q->front->move);
        dequeue(q);
        
        printf("\nLangkah %d: %s", ++step, move);
        printPuzzle(current);
        
        if (isGoal(current, tujuan)) {
            printf("Puzzle berhasil diselesaikan dalam %d langkah!\n\n", step);
            return;
        }
        
        int x, y;
        findEmptyPosition(current, &x, &y);
        
        if (x > 0) {
            int newPuzzle[SIZE][SIZE];
            generateNewState(current, newPuzzle, x, y, x-1, y);
            if (!isVisited(newPuzzle, visited)) {
                char moveDesc[20];
                sprintf(moveDesc, "%d ke atas", current[x-1][y]);
                enqueue(q, newPuzzle, moveDesc);
                enqueue(visited, newPuzzle, "");
            }
        }
        
        if (x < SIZE - 1) { 
            int newPuzzle[SIZE][SIZE];
            generateNewState(current, newPuzzle, x, y, x+1, y);
            if (!isVisited(newPuzzle, visited)) {
                char moveDesc[20];
                sprintf(moveDesc, "%d ke bawah", current[x+1][y]);
                enqueue(q, newPuzzle, moveDesc);
                enqueue(visited, newPuzzle, "");
            }
        }
        
        if (y > 0) {
            int newPuzzle[SIZE][SIZE];
            generateNewState(current, newPuzzle, x, y, x, y-1);
            if (!isVisited(newPuzzle, visited)) {
                char moveDesc[20];
                sprintf(moveDesc, "%d ke kiri", current[x][y-1]);
                enqueue(q, newPuzzle, moveDesc);
                enqueue(visited, newPuzzle, "");
            }
        }
        
        if (y < SIZE - 1) { 
            int newPuzzle[SIZE][SIZE];
            generateNewState(current, newPuzzle, x, y, x, y+1);
            if (!isVisited(newPuzzle, visited)) {
                char moveDesc[20];
                sprintf(moveDesc, "%d ke kanan", current[x][y+1]);
                enqueue(q, newPuzzle, moveDesc);
                enqueue(visited, newPuzzle, "");
            }
        }
    }
    
    printf("Tidak ditemukan solusi untuk puzzle ini.\n");
}

int main() {
    int awal[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };
    
    int tujuan[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    
    printf("Puzzle awal:");
    printPuzzle(awal);
    
    printf("Puzzle tujuan:");
    printPuzzle(tujuan);
    
    printf("Memulai penyelesaian puzzle...\n");
    solvePuzzle(awal, tujuan);
    
    return 0;
}
