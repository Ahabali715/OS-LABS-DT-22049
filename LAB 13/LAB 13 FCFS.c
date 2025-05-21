#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);

    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");
    scanf("%d", &initial);

    // Logic for SSTF disk scheduling
    while (count != n)
    {
        int min = 10000, d, index = -1;

        for (i = 0; i < n; i++)
        {
            if (RQ[i] != -1) // Only consider unvisited requests
            {
                d = abs(RQ[i] - initial);
                if (min > d)
                {
                    min = d;
                    index = i;
                }
            }
        }

        if (index == -1) // All requests served
            break;

        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = -1; // Mark as served
        count++;
    }

    printf("Total head movement is %d\n", TotalHeadMovement);

    return 0;
}
