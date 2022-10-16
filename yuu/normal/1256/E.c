#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
struct student_t {
    int a, i;
} s[200001], buffer[200001];

int t[200001];
int f[200001];
int trace[200001];

void merge_sort(int l, int r) {
    if (l + 1 >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);
    int x = l, y = m, pos = 0;
    while ((x < m) && (y < r)) {
        if (s[x].a < s[y].a) buffer[pos++] = s[x++];
        else buffer[pos++] = s[y++];
    }
    while (x < m) buffer[pos++] = s[x++];
    while (y < r) buffer[pos++] = s[y++];
    for (int i = l; i < r; i++) s[i] = buffer[i - l];
}

int team = 0;
void find_trace(int u) {
    if (u == 0) return;
    find_trace(trace[u]);
    team++;
    for (int j = trace[u] + 1; j <= u; j++) t[s[j].i] = team;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i].a);
        s[i].i = i;
    }
    merge_sort(1, n + 1);
    for (int i = 1; i <= n; i++) f[i] = 1.1e9;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 3; j >= i - 5; j--) {
            if (j < 0) break;
            if (f[i] > f[j] + s[i].a - s[j + 1].a) {
                f[i] = f[j] + s[i].a - s[j + 1].a;
                trace[i] = j;
            }
        }
    }
    find_trace(n);
    printf("%d %d\n", f[n], t[s[n].i]);
    for (int i = 1; i <= n; i++) printf("%d ", t[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}