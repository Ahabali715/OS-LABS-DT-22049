#include <stdio.h>
#include <conio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main()
{
    printf("********** Deadlock Detection Algorithm ************\n");
    input();
    show();
    cal();
    getch();
    return 0;
}

void input()
{
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
    }
}

void show()
{
    int i, j;
    printf("\nProcess\t Allocation\t Max\t\t Available\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t ", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t ");

        for (j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t ");
        if (i == 0)
        {
            for (j = 0; j < r; j++)
            {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void cal()
{
    int finish[100], dead[100], safe[100];
    int i, j, k, c, c1 = 0, flag = 1, dead_count = 0;

    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    // Calculate need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Deadlock detection algorithm
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                c = 0;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] <= avail[j])
                    {
                        c++;
                    }
                }

                if (c == r)
                {
                    for (j = 0; j < r; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
    }

    // Check for deadlock
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            dead[dead_count++] = i;
        }
    }

    if (dead_count > 0)
    {
        printf("\n\nSystem is in Deadlock.\nDeadlocked processes are:\n");
        for (i = 0; i < dead_count; i++)
        {
            printf("P%d\t", dead[i] + 1);
        }
        printf("\n");
    }
    else
    {
        printf("\n\nNo Deadlock Detected. System is in a Safe State.\n");
    }
}
