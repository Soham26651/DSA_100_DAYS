/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated
Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
int main() {
    int n, key, i;
    struct Node *head = NULL, *tail = NULL, *newNode;

    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &key);

    struct Node *curr = head, *prev = NULL;

    while(curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL) 
    {  
        if(prev == NULL)
            head = curr->next;
        else
            prev->next = curr->next;

        free(curr);
    }

    curr = head;
    while(curr != NULL) 
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    return 0;
}