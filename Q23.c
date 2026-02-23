/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated
Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
int main() {
    int n, m, i;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp, *newNode;

    printf("Enter size of first list: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head1 == NULL)
            head1 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    printf("Enter size of second list: ");
    scanf("%d", &m);

    printf("Enter sorted elements: ");
    for(i = 0; i < m; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head2 == NULL)
            head2 = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    struct Node *merged = NULL, *last = NULL;

    while(head1 && head2) 
    {
        struct Node *smaller;

        if(head1->data < head2->data) {
            smaller = head1;
            head1 = head1->next;
        } else {
            smaller = head2;
            head2 = head2->next;
        }
        if(merged == NULL)
            merged = smaller;
        else
            last->next = smaller;

        last = smaller;
    }
    if(head1)
        last->next = head1;
    else
        last->next = head2;

    printf("Merged List: ");
    while(merged) {
        printf("%d ", merged->data);
        merged = merged->next;
    }
    return 0;
}