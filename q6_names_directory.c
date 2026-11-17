/* Q6. A Directory of Names - Sorting and Searching Strings */
#include <stdio.h>
#include <string.h>

#define MAX 500

int main(void)
{
    char names[MAX][30];
    char temp[30];
    char key[30];
    int n, i, j;
    int low, high, mid = 0;
    int found = 0;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid count\n");
        return 1;
    }
    getchar(); /* consume newline */

    printf("Enter student names:\n");
    for (i = 0; i < n; i++)
    {
        fgets(names[i], 30, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    /* Bubble sort using strcmp */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Names:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", names[i]);

    /* Duplicate detection: equal names are adjacent after sorting */
    printf("\nDuplicate Names:\n");
    for (i = 0; i < n - 1; i++)
        if (strcmp(names[i], names[i + 1]) == 0)
            printf("%s\n", names[i]);

    /* Binary search */
    printf("\nEnter name to search: ");
    fgets(key, 30, stdin);
    key[strcspn(key, "\n")] = '\0';

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int result = strcmp(names[mid], key);
        if (result == 0)
        {
            found = 1;
            break;
        }
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found)
        printf("Name Found at position %d\n", mid + 1);
    else
        printf("Name Not Found\n");
    return 0;
}
