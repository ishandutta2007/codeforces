#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_prime_factor(int n) {
    int ans = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                ans++;
            }
        }
    }
    if (n > 1) ans++;
    return ans;
}

void solve() {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    if (k == 1) {
        if ((a != b) && ((a % b == 0) || (b % a == 0))) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        if (get_prime_factor(a) + get_prime_factor(b) >= k) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}