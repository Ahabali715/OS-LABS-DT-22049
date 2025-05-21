#include <stdio.h>

int main() {
    int p[10], np, b[10], nb, ch, c[10], d[10], alloc[10], flag[10], i, j;

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the size of each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i);
        scanf("%d", &p[i]);
    }

    printf("Enter the size of each block:\n");
    for (j = 0; j < nb; j++) {
        printf("Block %d: ", j);
        scanf("%d", &b[j]);
        c[j] = b[j];
        d[j] = b[j];
    }

    if (np <= nb) {
        printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");

        do {
            printf("\nEnter your choice: ");
            scanf("%d", &ch);

            // Reset block arrays and flags
            for (i = 0; i < nb; i++) {
                b[i] = c[i];
                c[i] = d[i];
                d[i] = b[i];
            }
            for (i = 0; i < np; i++)
                flag[i] = 1;

            switch (ch) {
                case 1:
                    printf("\n--- First Fit ---\n");
                    for (i = 0; i < np; i++) {
                        for (j = 0; j < nb; j++) {
                            if (p[i] <= b[j]) {
                                alloc[j] = p[i];
                                printf("\nProcess %d of size %d is allocated in block %d of size %d", i, p[i], j, b[j]);
                                flag[i] = 0;
                                b[j] = 0;
                                break;
                            }
                        }
                    }
                    break;

                case 2:
                    printf("\n--- Best Fit ---\n");
                    // Sort c[] ascending
                    for (i = 0; i < nb - 1; i++) {
                        for (j = i + 1; j < nb; j++) {
                            if (c[i] > c[j]) {
                                int temp = c[i];
                                c[i] = c[j];
                                c[j] = temp;
                            }
                        }
                    }
                    for (i = 0; i < np; i++) {
                        for (j = 0; j < nb; j++) {
                            if (p[i] <= c[j]) {
                                alloc[j] = p[i];
                                printf("\nProcess %d of size %d is allocated in block %d of size %d", i, p[i], j, c[j]);
                                flag[i] = 0;
                                c[j] = 0;
                                break;
                            }
                        }
                    }
                    break;

                case 3:
                    printf("\n--- Worst Fit ---\n");
                    // Sort d[] descending
                    for (i = 0; i < nb - 1; i++) {
                        for (j = i + 1; j < nb; j++) {
                            if (d[i] < d[j]) {
                                int temp = d[i];
                                d[i] = d[j];
                                d[j] = temp;
                            }
                        }
                    }
                    for (i = 0; i < np; i++) {
                        for (j = 0; j < nb; j++) {
                            if (p[i] <= d[j]) {
                                alloc[j] = p[i];
                                printf("\nProcess %d of size %d is allocated in block %d of size %d", i, p[i], j, d[j]);
                                flag[i] = 0;
                                d[j] = 0;
                                break;
                            }
                        }
                    }
                    break;

                default:
                    printf("\nInvalid Choice…!");
                    break;
            }

            // Show unallocated processes
            for (i = 0; i < np; i++) {
                if (flag[i])
                    printf("\nProcess %d of size %d is not allocated", i, p[i]);
            }

        } while (ch <= 3);
    } else {
        printf("\nNumber of processes must be less than or equal to number of blocks.\n");
    }

    return 0;
}
