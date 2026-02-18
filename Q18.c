/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array
Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/
#include <stdio.h>

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    printf("Enter number of rotations: ");
    scanf("%d", &k);

    k = k % n;

    for (int i = 0; i < n; i++) 
    {
        b[(i + k) % n] = a[i];
    }
    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", b[i]);
    }
    return 0;
}
