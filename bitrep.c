#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    int w;
    printf("Enter the number of bits (e.g., 4 or 8): ");
    scanf("%d", &w);

    if (w <= 0 || w > (int)(sizeof(int) * 8)) {
        printf("Invalid bit width.\n");
        return 1;
    }

    // 1. Unsigned range
    unsigned int unsigned_min = 0;
    unsigned int unsigned_max = (1U << w) - 1;

    // 2. Two's complement range
    int tc_min = -(1 << (w - 1));
    int tc_max = (1 << (w - 1)) - 1;

    printf("\n=== For w = %d bits ===\n", w);
    printf("Unsigned Min: %u\n", unsigned_min);
    printf("Unsigned Max: %u\n", unsigned_max);
    printf("Two's Complement Min: %d\n", tc_min);
    printf("Two's Complement Max: %d\n", tc_max);

    // 3. Convert Unsigned → Two's Complement
    unsigned int u;
    printf("\nEnter an unsigned value (0 to %u): ", unsigned_max);
    scanf("%u", &u);
    if (u > unsigned_max) {
        printf("Value out of range!\n");
        return 1;
    }

    int tc;
    if (u <= (unsigned_max >> 1)) {
        tc = (int)u; // same value
    } else {
        tc = (int)u - (1 << w); // subtract 2^w
    }
    printf("Unsigned %u in Two's Complement = %d\n", u, tc);

    // 4. Convert Two's Complement → Unsigned
    printf("\nEnter a two's complement value (%d to %d): ", tc_min, tc_max);
    scanf("%d", &tc);
    if (tc < tc_min || tc > tc_max) {
        printf("Value out of range!\n");
        return 1;
    }

    if (tc >= 0) {
        u = (unsigned int)tc;
    } else {
        u = (unsigned int)(tc + (1 << w)); // add 2^w
    }
    printf("Two's Complement %d in Unsigned = %u\n", tc, u);

    return 0;
}
