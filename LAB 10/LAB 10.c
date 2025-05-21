#include <stdio.h>
#include <stdlib.h>  // For exit()

int main() {
    int base[20], limit[20], n, i, pa, d, seg;

    printf("Program for Segmentation\n");

    // Get number of segments
    printf("Enter the number of segments: ");
    scanf("%d", &n);

    // Get base and limit for each segment
    printf("Enter the base address and limit for each segment:\n");
    for (i = 0; i < n; i++) {
        printf("Segment %d Base: ", i);
        scanf("%d", &base[i]);
        printf("Segment %d Limit: ", i);
        scanf("%d", &limit[i]);
    }

    // Get logical address
    printf("Enter the segment number and offset (logical address):\n");
    printf("Segment: ");
    scanf("%d", &seg);
    printf("Offset: ");
    scanf("%d", &d);

    // Check for valid segment and offset
    if (seg >= n || seg < 0) {
        printf("Invalid segment number!\n");
    } else if (d >= limit[seg]) {
        printf("Offset exceeds segment limit!\n");
    } else {
        pa = base[seg] + d;
        printf("\nSegment\tBase\tLimit\tOffset\tPhysical Address\n");
        printf("%d\t%d\t%d\t%d\t%d\n", seg, base[seg], limit[seg], d, pa);
    }

    return 0;
}
