#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    int f[50], i, st, j, len, c;


    // Initialize all blocks as free (0)
    for (i = 0; i < 50; i++)
        f[i] = 0;

    while (1) {
        printf("\nEnter the starting block and length of file: ");
        scanf("%d%d", &st, &len);

        // Check if blocks from st to st+len-1 are free
        for (j = st; j < st + len; j++) {
            if (j >= 50) {
                printf("Block number %d is out of range.\n", j);
                break;
            }
            if (f[j] == 1) {
                printf("Block %d already allocated\n", j);
                break;
            }
        }

        if (j == st + len) {  // All blocks are free
            for (j = st; j < st + len; j++) {
                f[j] = 1;
                printf("%d -> %d\n", j, f[j]);
            }
            printf("The file is allocated to disk\n");
        } else {
            printf("File allocation failed\n");
        }

        printf("Do you want to enter more files? (y-1/n-0): ");
        scanf("%d", &c);

        if (c != 1)
            break;
    }

    getch();
    return 0;
}
