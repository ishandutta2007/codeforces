#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[3];
int b[3];
int x[3], y[3];

int min(int a, int b) { return (a < b) ? a : b; }

int m_a[] = {0, 0, 1, 1, 2, 2};
int m_b[] = {0, 2, 1, 0, 2, 1};

bool used[6];
int order[6];

int ans_min = 1e9;

void update_min() {
    for (int i = 0; i < 3; i++) {
        x[i] = a[i];
        y[i] = b[i];
    }
    int res = n;
    for (int i = 0; i < 6; i++) {
        int j = order[i];
        int spent = min(x[m_a[j]], y[m_b[j]]);
        x[m_a[j]] -= spent;
        y[m_b[j]] -= spent;
        res -= spent;
    }
    ans_min = min(ans_min, res);
}

void backtrack(int u) {
    if (u == 6) {
        update_min();
    } else {
        for (int i = 0; i < 6; i++)
            if (!used[i]) {
                order[u] = i;
                used[i] = 1;
                backtrack(u + 1);
                used[i] = 0;
            }
    }
}

int get_min() {
    backtrack(0);
    return ans_min;
}

int get_max() {
    for (int i = 0; i < 3; i++) {
        x[i] = a[i];
        y[i] = b[i];
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int best = min(x[i], y[(i + 1) % 3]);
        ans += best;
    }
    return ans;
}

void solve() {
    scanf("%d\n", &n);
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    printf("%d %d\n", get_min(), get_max());
}
int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}