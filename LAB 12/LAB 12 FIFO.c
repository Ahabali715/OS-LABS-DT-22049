#include <stdio.h>

int main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25];
    int n, f, pf = 0, next = 1;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    printf("\nThe Page Replacement process is:\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in a frame
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                count[j] = next++;  // Update time of use
                break;
            }
        }

        // If page is not found -> Page Fault
        if (!found) {
            int replace_index = 0;

            // If there is space in frames
            if (i < f) {
                replace_index = i;
            } else {
                // Find least recently used page (smallest count)
                for (j = 1; j < f; j++) {
                    if (count[j] < count[replace_index]) {
                        replace_index = j;
                    }
                }
            }

            // Replace page
            m[replace_index] = rs[i];
            count[replace_index] = next++;
            pf++;
        }

        // Print frame contents
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("%d\t", m[j]);
            else
                printf("-\t");
        }

        if (!found)
            printf("PF No. -- %d", pf);
        printf("\n");
    }

    printf("\nTotal number of page faults using LRU: %d\n", pf);

    return 0;
}
