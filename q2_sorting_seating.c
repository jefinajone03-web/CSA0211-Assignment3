/* Q2. Sorting the Examination Hall Seating Register
   Bubble Sort, Selection Sort and Insertion Sort */
#include <stdio.h>

void bubble(int a[], int n)
{
    int i, j, temp, flag;
    int comp = 0, swaps = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            comp++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swaps++;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    printf("Bubble Sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nComparisons = %d, Swaps = %d\n", comp, swaps);
}

void selection(int a[], int n)
{
    int i, j, min, temp;
    int comp = 0, swaps = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            comp++;
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swaps++;
        }
    }
    printf("Selection Sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nComparisons = %d, Swaps = %d\n", comp, swaps);
}

void insertion(int a[], int n)
{
    int i, j, key;
    int comp = 0, shifts = 0;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0)
        {
            comp++;
            if (a[j] > key)
            {
                a[j + 1] = a[j];
                shifts++;
                j--;
            }
            else
                break;
        }
        a[j + 1] = key;
    }
    printf("Insertion Sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nComparisons = %d, Shifts = %d\n", comp, shifts);
}

int main(void)
{
    int a[] = {45, 12, 30, 8, 25};
    int b[] = {45, 12, 30, 8, 25};
    int c[] = {45, 12, 30, 8, 25};
    int n = 5;

    bubble(a, n);
    selection(b, n);
    insertion(c, n);
    return 0;
}
