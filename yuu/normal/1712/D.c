#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;
int a[100001];
int b[100001];

bool check(int req) {
    for (int i = 1; i <= n; i++) b[i] = a[i];
    int allowed = k;
    for (int i = 1; i <= n; i++)
        if (b[i] * 2 < req) {
            allowed--;
            if (allowed < 0) return 0;
            b[i] = 1e9;
        }
    if (allowed >= 2) return 1;
    if (allowed == 0) {
        for (int i = 1; i < n; i++)
            if ((b[i] >= req) && (b[i + 1] >= req)) return 1;
        return 0;
    } else {
        for (int i = 1; i <= n; i++)
            if (b[i] >= req) return 1;
        return 0;
    }
}
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int low = 1, high = 1e9, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%d\n", res);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}