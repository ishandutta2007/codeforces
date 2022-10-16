#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int have[200003];
int covered[200003];
int find_low() {
    for (int i = 0; i <= n + 1; i++) have[i] = 0;
    for (int i = 1; i <= n; i++) have[a[i]] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (have[i]) {
            ans++;
            have[i + 1] = have[i + 2] = 0;
        }
    }
    return ans;
}
int find_high() {
    for (int i = 0; i <= n + 1; i++) have[i] = 0;
    for (int i = 1; i <= n; i++) have[a[i]]++;
    for (int i = 1; i <= n; i++) {
        if (have[i]) {
            if (!covered[i - 1]) {
                covered[i - 1] = 1;
                have[i]--;
            }
        }
        if (have[i]) {
            if (!covered[i]) {
                covered[i] = 1;
                have[i]--;
            }
        }
        if (have[i]) {
            covered[i + 1] = 1;
            have[i]--;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n + 1; i++) ans += covered[i];
    return ans;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%d %d\n", find_low(), find_high());
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}