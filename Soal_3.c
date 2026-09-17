#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



#define MOD 1000000007


int compare(const void *a, const void *b) {
    long long arg1 = *(const long long *)a;
    long long arg2 = *(const long long *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *a = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    
    qsort(a, n, sizeof(long long), compare);

    
    long long total_pairs = (long long)n * (n - 1) / 2;

    
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        long long count = j - i;
        long long equal_pairs = count * (count - 1) / 2;
        total_pairs -= equal_pairs;
        i = j;
    }

    free(a);

    
    long long ans = total_pairs % MOD;
    printf("%lld\n", ans);

    return 0;
}