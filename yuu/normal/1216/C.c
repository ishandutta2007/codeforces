#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int64_t x[10], y[10], u[10], v[10];

void make_union(int a, int b, int r) {
    x[r] = (x[a] > x[b]) ? x[a] : x[b];
    y[r] = (y[a] > y[b]) ? y[a] : y[b];
    u[r] = (u[a] < u[b]) ? u[a] : u[b];
    v[r] = (v[a] < v[b]) ? v[a] : v[b];
}

int64_t area(int r) {
    if (x[r] >= u[r]) return 0;
    if (y[r] >= v[r]) return 0;
    return (u[r] - x[r]) * (v[r] - y[r]);
}

int64_t area_of_union(int a, int b) {
    make_union(a, b, 9);
    return area(9);
}

void solve() {
    for (int i = 0; i < 3; i++) scanf("%d %d %d %d", &x[i], &y[i], &u[i], &v[i]);
    make_union(1, 2, 3);
    int64_t not_covered = area(0) - area_of_union(0, 1) - area_of_union(0, 2) + area_of_union(0, 3);
    if (not_covered > 0) puts("YES");
    else puts("NO");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}