/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/
#include <stdio.h>

int main()
{
    char s[100];
    int i, len = 0;

    printf("Enter a string: ");
    scanf("%s", s);

    while (s[len] != '\0')
        len++;

    for (i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");

    return 0;
}
