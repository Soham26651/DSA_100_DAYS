/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements
Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1
*/
#include <stdio.h>
int main()
{
    int n, num, max, min;

    printf("Enter n: ");
    scanf("%d", &n);

    scanf("%d", &num);
    max = min = num;

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &num);

        if (num > max)
            max = num;

        if (num < min)
            min = num;
    }
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
