/* Q4. Two-Dimensional Arrays - District Rainfall Records
   38 districts x 12 months */
#include <stdio.h>

#define D 38
#define M 12

void annual_total(int rain[D][M])
{
    int i, j, total;
    for (i = 0; i < D; i++)
    {
        total = 0;
        for (j = 0; j < M; j++)
            total += rain[i][j];
        printf("District %d Total = %d\n", i + 1, total);
    }
}

void monthly_average(int rain[D][M])
{
    int i, j, total;
    for (j = 0; j < M; j++)
    {
        total = 0;
        for (i = 0; i < D; i++)
            total += rain[i][j];
        printf("Month %d Average = %.2f\n", j + 1, (float)total / D);
    }
}

void maximum_rainfall(int rain[D][M])
{
    int i, j;
    int max = rain[0][0];
    int district = 0, month = 0;
    for (i = 0; i < D; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (rain[i][j] > max)
            {
                max = rain[i][j];
                district = i;
                month = j;
            }
        }
    }
    printf("Maximum Rainfall = %d\n", max);
    printf("District = %d, Month = %d\n", district + 1, month + 1);
}

void deficient_districts(int rain[D][M])
{
    int i, j;
    float state_total = 0, average;

    for (i = 0; i < D; i++)
        for (j = 0; j < M; j++)
            state_total += rain[i][j];

    /* average annual rainfall per district */
    average = state_total / D;
    printf("State Annual Average = %.2f\n", average);
    printf("Deficient Districts:\n");

    for (i = 0; i < D; i++)
    {
        int total = 0;
        for (j = 0; j < M; j++)
            total += rain[i][j];
        if (total < 0.60 * average)
            printf("District %d\n", i + 1);
    }
}

int main(void)
{
    int rain[D][M];
    int i, j;

    printf("Enter rainfall for 38 districts and 12 months:\n");
    for (i = 0; i < D; i++)
        for (j = 0; j < M; j++)
            if (scanf("%d", &rain[i][j]) != 1)
            {
                printf("Invalid input\n");
                return 1;
            }

    printf("\nAnnual Totals:\n");
    annual_total(rain);
    printf("\nMonthly Averages:\n");
    monthly_average(rain);
    printf("\nMaximum Rainfall:\n");
    maximum_rainfall(rain);
    printf("\nDeficient Districts:\n");
    deficient_districts(rain);
    return 0;
}
