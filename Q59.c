/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree
Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int x){
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}
int search(int in[], int s, int e, int x){
    for(int i=s;i<=e;i++)
        if(in[i]==x) return i;
    return -1;
}
int postIndex;

struct Node* build(int in[], int post[], int s, int e){
    if(s > e) return NULL;

    struct Node* root = newNode(post[postIndex--]);

    int pos = search(in, s, e, root->data);

    root->right = build(in, post, pos+1, e); // IMPORTANT
    root->left  = build(in, post, s, pos-1);

    return root;
}
void pre(struct Node* r){
    if(!r) return;

    printf("%d ", r->data);
    pre(r->left);
    pre(r->right);
}
int main(){
    int n;
    scanf("%d",&n);

    int in[n], post[n];

    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);

    postIndex = n-1;

    struct Node* root = build(in, post, 0, n-1);

    pre(root);

    return 0;
}