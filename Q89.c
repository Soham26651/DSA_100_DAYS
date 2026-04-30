/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113
*/
#include <stdio.h>

int can(int a[], int n, int m, int max) {
    int students = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= max)
            sum += a[i];
        else {
            students++;
            sum = a[i];
        }
    }
    return students <= m;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = a[0], r = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > l) l = a[i]; // max element
        r += a[i];              // total sum
    }
    int ans = r;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (can(a, n, m, mid)) 
        {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}