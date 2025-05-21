#include <stdio.h>
#include <conio.h>

int main()
{
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = 0;   // Starting from 0, assuming disk starts at track 0
    t[1] = h;   // Initial head position

    printf("Enter the tracks: ");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);

    // Sort the array t[]
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < (n + 2) - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of head in the sorted array
    for (i = 0; i < n + 2; i++)
    {
        if (t[i] == h)
        {
            j = i;
            k = i;
            break;
        }
    }

    p = 0;

    // Store left side tracks from head in reverse order
    while (j >= 0)
    {
        atr[p] = t[j];
        j--;
        p++;
    }

    // Store right side tracks from head onwards
    for (j = k + 1; j < n + 2; j++, p++)
    {
        atr[p] = t[j];
    }

    // Calculate distances between successive tracks and sum them
    for (i = 0; i < n + 1; i++)
    {
        if (atr[i] > atr[i + 1])
            d[i] = atr[i] - atr[i + 1];
        else
            d[i] = atr[i + 1] - atr[i];

        sum += d[i];
    }

    printf("\nAverage header movements: %f\n", (float)sum / n);

    getch();
    return 0;
}
