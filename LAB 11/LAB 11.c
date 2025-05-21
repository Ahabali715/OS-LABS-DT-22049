#include <stdio.h>

int main() {
    int i, j, k, f, pf = 0, count = 0;
    int rs[25], m[10], n;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1;  // Initialize all frames to -1 (empty)

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {
        // Check if page is already in a frame
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i])
                break;
        }

        // If not found (page fault)
        if (k == f) {
            m[count] = rs[i]; // Replace oldest page
            count = (count + 1) % f; // FIFO rotation
            pf++;
        }

        // Print current frame contents
        for (j = 0; j < f; j++) {
            if (m[j] == -1)
                printf("\t-");
            else
                printf("\t%d", m[j]);
        }

        // Indicate page fault
        if (k == f)
            printf("\tPF No. %d", pf);
        printf("\n");
    }

    printf("\nTotal Page Faults using FIFO: %d\n", pf);
    return 0;
}
