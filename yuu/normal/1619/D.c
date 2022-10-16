
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int m, n;
int* p[100000];
bool good[100000];
bool check(int lim) {
    for (int i = 0; i < n; i++) good[i] = false;
    bool good_overall = false;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (p[i][j] >= lim) {
                good[j] = true;
                cnt++;
            }
        }
        if (cnt > 1) good_overall = true;
    }
    if (!good_overall) return false;
    for (int j = 0; j < n; j++)
        if (!good[j]) return false;
    return true;
}

void solve() {
    scanf("%d %d\n", &m, &n);
    for (int i = 0; i < m; i++) {
        p[i] = malloc(n * 4);
        for (int j = 0; j < n; j++) scanf("%d", p[i] + j);
    }
    int low = 2, high = 1e9, ans = 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    for (int i = 0; i < m; i++) free(p[i]);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}