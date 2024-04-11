#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int cnt[200001];
int ft[200001];
int cost[200001];
int root[200001];
void update(int u) {
    for (; u <= n; u += u & -u) ft[u]++;
}

int get_min() {
    int step = 1;
    while (step * 2 <= n) step *= 2;
    int u = 0;
    while (step) {
        if (ft[u + step] == 0) u += step;
        do {
            step /= 2;
        } while (u + step > n);
    }
    for (int v = u + 1; v <= n; v += v & -v) ft[v]--;
    return u + 1;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cost[i] = i;
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0) update(cost[i]);
    printf("%d\n", a[1]);
    for (int i = n - 1; i >= 1; i--) {
        int min_cost = get_min();
        printf("%d %d\n", a[i], root[min_cost]);
        if (cost[a[i]] < min_cost) cost[a[i]] = min_cost;
        root[cost[a[i]]] = a[i];
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) update(cost[a[i]]);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}