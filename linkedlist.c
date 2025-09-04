#include <stdio.h>
#include <stdlib.h>

void main(void){
    int i;

    struct ListEntry { 
        int number;
        struct ListEntry *next;
    } start, *node;

start.next = NULL;

node = &start;

for (i = 1; i <= 10; i ++) {
    node->next = (struct ListEntry *)
        malloc(sizeof(struct ListEntry));
    node = node->next;
    node->number = i;
    node->next = NULL;
}
node = start.next;

while (node) {
    printf("%d ", node->number);
    node = node->next;
}

}