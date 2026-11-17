/* Q7. Election Counting Program */
#include <stdio.h>

#define MAX 12

int main(void)
{
    int count[MAX] = {0};
    int id[MAX];
    int votes, candidates;
    int valid = 0, invalid = 0;
    int i, j, temp;

    printf("Enter number of candidates: ");
    if (scanf("%d", &candidates) != 1 || candidates < 1 || candidates > MAX)
    {
        printf("Invalid candidate count\n");
        return 0;
    }

    printf("Enter number of votes: ");
    if (scanf("%d", &votes) != 1 || votes < 0 || votes > 500000)
    {
        printf("Invalid vote count\n");
        return 0;
    }

    printf("Enter votes:\n");
    for (i = 0; i < votes; i++)
    {
        int v;
        if (scanf("%d", &v) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }
        if (v >= 1 && v <= candidates)
        {
            count[v - 1]++;
            valid++;
        }
        else
            invalid++;
    }

    for (i = 0; i < candidates; i++)
        id[i] = i + 1;

    /* Bubble sort candidates by votes (descending) */
    for (i = 0; i < candidates - 1; i++)
        for (j = 0; j < candidates - i - 1; j++)
            if (count[id[j] - 1] < count[id[j + 1] - 1])
            {
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }

    printf("\nValid Votes = %d\n", valid);
    printf("Invalid Votes = %d\n", invalid);
    printf("\nElection Results:\n");
    for (i = 0; i < candidates; i++)
        printf("Candidate %d = %d votes\n", id[i], count[id[i] - 1]);

    printf("\n");
    if (count[id[0] - 1] == 0)
        printf("No winner. No valid votes.\n");
    else
    {
        int tie = 0;
        for (i = 1; i < candidates; i++)
            if (count[id[i] - 1] == count[id[0] - 1])
                tie++;

        if (tie > 0)
        {
            printf("Election Result: Tie\n");
            printf("Candidates with highest votes:\n");
            for (i = 0; i < candidates; i++)
                if (count[id[i] - 1] == count[id[0] - 1])
                    printf("Candidate %d\n", id[i]);
        }
        else
            printf("Winner: Candidate %d\n", id[0]);
    }
    return 0;
}
