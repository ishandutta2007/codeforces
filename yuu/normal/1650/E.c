#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, d;
int a[200002];
int max_gap[200002];
int min_gap[200002];

int get_best(int min_gap, int max_gap, int last_day) {
    max_gap = (max_gap - 1) / 2;                             // insert in between some gaps
    if (max_gap < d - last_day) max_gap = d - last_day - 1;  // insert at the very end
    if (max_gap >= min_gap) max_gap = min_gap;
    return max_gap;
}

int min(const int a, const int b) { return (a < b) ? (a) : (b); }
int max(const int a, const int b) { return (a > b) ? (a) : (b); }

void solve() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    max_gap[1] = min_gap[1] = a[1] - 1;
    for (int i = 2; i <= n; i++) {
        max_gap[i] = max_gap[i - 1];
        min_gap[i] = min_gap[i - 1];
        if (a[i] - a[i - 1] - 1 > max_gap[i])
            max_gap[i] = a[i] - a[i - 1] - 1;
        else if (a[i] - a[i - 1] - 1 < min_gap[i])
            min_gap[i] = a[i] - a[i - 1] - 1;
    }

    // case of moving n, no need to get correct max_gap
    int muse = get_best(min_gap[n - 1], max_gap[n - 1], a[n - 1]);
    int max_rgap = 0;
    int min_rgap = 2e9;
    max_gap[0] = 0;
    min_gap[0] = 2e9;
    for (int i = n - 1; i >= 1; i--) {
        int new_gap = a[i + 1] - a[i - 1] - 1;
        int new_min_gap = min(min_rgap, min(min_gap[i - 1], new_gap));
        int new_max_gap = max(max_rgap, max(max_gap[i - 1], new_gap));

        muse = max(muse, get_best(new_min_gap, new_max_gap, a[n]));

        int rgap = a[i + 1] - a[i] - 1;
        max_rgap = max(max_rgap, rgap);
        min_rgap = min(min_rgap, rgap);
    }
    printf("%d\n", muse);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}