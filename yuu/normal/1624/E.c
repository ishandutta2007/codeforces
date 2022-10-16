#include <stdio.h>
int n, m;
struct {
    int l, r, i;
} pattern_2[101], pattern_3[1001];
char c[1001][1001];
char s[1001];
int trace[1001];
int trace_type[1001];

void trace_back(int u, int cnt) {
    if (u == 0) {
        printf("%d\n", cnt);
        return;
    }
    if (trace_type[u] == 2) {
        trace_back(u - 2, cnt + 1);
        printf("%d %d %d\n", pattern_2[trace[u]].l, pattern_2[trace[u]].r, pattern_2[trace[u]].i);
    } else {
        trace_back(u - 3, cnt + 1);
        printf("%d %d %d\n", pattern_3[trace[u]].l, pattern_3[trace[u]].r, pattern_3[trace[u]].i);
    }
}

void solve() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s\n", c[i]);
        for (int j = 0; j < m; j++) c[i][j] -= '0';
    }
    scanf("%s\n", s);
    for (int j = 0; j < m; j++) s[j] -= '0';
    for (int i = 0; i < 100; i++) pattern_2[i].i = -1;
    for (int i = 0; i < 1000; i++) pattern_3[i].i = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = c[i][j];
            if (j + 1 < m) {
                val *= 10;
                val += c[i][j + 1];
                if (pattern_2[val].i == -1) {
                    pattern_2[val].i = i + 1;
                    pattern_2[val].l = j + 1;
                    pattern_2[val].r = j + 1 + 1;
                }
            }
            if (j + 2 < m) {
                val *= 10;
                val += c[i][j + 2];
                if (pattern_3[val].i == -1) {
                    pattern_3[val].i = i + 1;
                    pattern_3[val].l = j + 1;
                    pattern_3[val].r = j + 2 + 1;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) trace[i] = -1;
    trace[0] = 0;
    for (int j = 0; j < m; j++)
        if (trace[j] != -1) {
            int val = s[j];
            if (j + 1 < m) {
                val *= 10;
                val += s[j + 1];
                if (pattern_2[val].i != -1) {
                    trace[j + 2] = val;
                    trace_type[j + 2] = 2;
                }
            }
            if (j + 2 < m) {
                val *= 10;
                val += s[j + 2];
                if (pattern_3[val].i != -1) {
                    trace[j + 3] = val;
                    trace_type[j + 3] = 3;
                }
            }
        }
    if (trace[m] == -1)
        printf("-1\n");
    else
        trace_back(m, 0);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}