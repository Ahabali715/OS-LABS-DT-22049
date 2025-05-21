#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], p, i, j, k, a, st, len, c;

    // Initialize all blocks as free (0)
    for(i = 0; i < 50; i++)
        f[i] = 0;

    // Input already allocated blocks
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers that are already allocated:\n");
    for(i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < 50)
            f[a] = 1;
        else
            printf("Block number %d is invalid and ignored.\n", a);
    }

    // Loop for multiple file allocations
    while (1) {
        printf("Enter the starting index block and length: ");
        scanf("%d%d", &st, &len);

        k = len;

        // Try to allocate blocks from st to st+len-1
        for(j = st; j < st + k; j++) {
            if (j < 0 || j >= 50) {
                printf("\nBlock number %d is invalid.\n", j);
                k++;  // Extend allocation to cover length despite invalid block
                continue;
            }

            if(f[j] == 0) {
                f[j] = 1;
                printf("\n%d -> allocated", j);
            } else {
                printf("\n%d -> file is already allocated", j);
                k++;  // Extend allocation to cover length despite allocated block
            }
        }

        printf("\nDo you want to enter one more file? (yes-1 / no-0): ");
        scanf("%d", &c);
        if(c != 1)
            break;
    }

    return 0;
}
