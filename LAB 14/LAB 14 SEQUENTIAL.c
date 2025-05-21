#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    int f[50], i, k, j, inde[50], n, c, p;

    // Initialize all blocks as free
    for(i = 0; i < 50; i++)
        f[i] = 0;

    while (1) {
        printf("Enter index block: ");
        scanf("%d", &p);

        if (p < 0 || p >= 50) {
            printf("Invalid block number. Try again.\n");
            continue;
        }

        if(f[p] == 0) {
            f[p] = 1;  // Allocate index block

            printf("Enter number of files on index: ");
            scanf("%d", &n);

            printf("Enter the file blocks:\n");
            for(i = 0; i < n; i++) {
                scanf("%d", &inde[i]);
                if(inde[i] < 0 || inde[i] >= 50) {
                    printf("Invalid block number %d. Try again.\n", inde[i]);
                    i--;  // Ask for the block again
                }
            }

            // Check if blocks are free
            for(i = 0; i < n; i++) {
                if(f[inde[i]] == 1) {
                    printf("Block %d already allocated. Allocation failed.\n", inde[i]);
                    f[p] = 0; // Free the index block since allocation failed
                    goto retry;
                }
            }

            // Allocate blocks for the file
            for(j = 0; j < n; j++)
                f[inde[j]] = 1;

            printf("\nFile allocated using index block %d:\n", p);
            for(k = 0; k < n; k++)
                printf("%d -> %d : %d\n", p, inde[k], f[inde[k]]);

        } else {
            printf("Block already allocated\n");
            retry:
            continue;
        }

        printf("Enter 1 to enter more files and 0 to exit: ");
        scanf("%d", &c);
        if(c != 1)
            break;
    }

    getch();
    return 0;
}
