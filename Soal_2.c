#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



void sort(long long *x, long long *y, long long *z) {
    if (*x > *y) { long long t = *x; *x = *y; *y = t; }
    if (*y > *z) { long long t = *y; *y = *z; *z = t; }
    if (*x > *y) { long long t = *x; *x = *y; *y = t; }
}

int main() {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) return 0;

    
    if (a == b || b == c || a == c) {
        printf("0\n");
        return 0;
    }


    long long x = a, y = b, z = c;
    sort(&x, &y, &z);

    
    long long ronde1 = y - x;
    long long ronde2 = z - y;
    long long ans = (ronde1 < ronde2) ? ronde1 : ronde2;

    
    if ((z - x) % 2 == 0) {
        long long ronde3 = (z - x) / 2;
        if (ronde3 < ans) {
            ans = ronde3;
        }
    }

    printf("%lld\n", ans);

    return 0;
}