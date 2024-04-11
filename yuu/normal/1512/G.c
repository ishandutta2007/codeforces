#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p[10000001];
int sum[10000001];
void prepare() {
    for (int i = 2; i <= 10000000; i++)
        if (p[i] == 0) {
            for (int j = i; j <= 10000000; j += i)
                if (p[j] == 0) p[j] = i;
        }
    sum[1] = 1;
    for (int i = 2; i <= 10000000; i++) {
        int64_t prime_sum = 1;
        const int prime = p[i];
        int weight = prime;
        int u = i;
        while (u % prime == 0) {
            prime_sum += weight;
            weight *= prime;
            u /= prime;
        }
        if (u > 1) prime_sum *= sum[u];
        if (prime_sum <= 10000000) sum[i] = prime_sum;
    }
    for (int i = 1; i <= 10000000; i++) p[i] = 0;
    for (int i = 1; i <= 10000000; i++) {
        if (sum[i]) {
            if (p[sum[i]] == 0) p[sum[i]] = i;
        }
    }
}
void solve() {
    int c;
    scanf("%d", &c);
    if (p[c])
        printf("%d\n", p[c]);
    else
        printf("-1\n");
}

int main() {
    prepare();
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}