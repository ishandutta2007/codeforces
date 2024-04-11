#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[200001];
int get_min_cost(int x, int y) {
    if (x > y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
    if (y >= x * 2) return (y - 1) / 2 + 1;
    // y - k*2 <= x - k
    // y - x <= k
    int k = y - x;
    y -= k * 2;
    x -= k;
    if (x > y) {
        x -= 2;
        y -= 1;
        k++;
    }
    assert(x == y);
    if (x <= 0) return k;
    int l = x / 3;
    k += l * 2;
    x -= l * 3;
    y -= l * 3;
    while ((x > 0) || (y > 0)) {
        if (x > y) {
            x -= 2;
            y -= 1;
        } else {
            y -= 2;
            x -= 1;
        }
        k++;
    }
    return k;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int mi = (a[1] - 1) / 2 + 1;
    int ans = 1e9;
    for (int i = 2; i <= n; i++) {
        int cost = (a[i] - 1) / 2 + 1;
        if (ans > mi + cost) ans = mi + cost;
        if (mi > cost) mi = cost;
        cost = get_min_cost(a[i - 1], a[i]);
        if (ans > cost) ans = cost;
    }
    for (int i = 2; i < n; i++) {
        int x = a[i - 1];
        int y = a[i - 1];
        if (a[i + 1] < x) x = a[i + 1];
        if (a[i + 1] > y) y = a[i + 1];
        int cost = x;
        y -= x;
        if (y) cost += (y - 1) / 2 + 1;
        if (ans > cost) ans = cost;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}