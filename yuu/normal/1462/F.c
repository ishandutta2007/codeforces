#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
struct {
    int pos;
    int id;
    int type;
} s[400001], buffer[400001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if ((s[x].pos < s[y].pos) || ((s[x].pos == s[y].pos) && (s[x].type < s[y].type))) buffer[pos++] = s[x++];
        else buffer[pos++] = s[y++];
    }
    while (x <= m) buffer[pos++] = s[x++];
    while (y <= r) buffer[pos++] = s[y++];
    for (int i = l; i <= r; i++) s[i] = buffer[i - l];
}

int ans[200001];
int start[200001];
int end[200001];

int end_count[400001];
int start_count[400002];
int ft[400002];
int update(int u) {
    for (; u <= 400000; u += (u & -u)) ft[u]++;
}
int get(int u) {
    int res = 0;
    for (; u > 0; u -= (u & -u)) res += ft[u];
    return res;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &s[i * 2 - 1].pos, &s[i * 2].pos);
        s[i * 2 - 1].id = i;
        s[i * 2].id = i;
        s[i * 2 - 1].type = 0;
        s[i * 2].type = 1;
    }
    merge_sort(1, n * 2);
    for (int i = 1, j = 1; i <= n * 2; i++) {
        if (s[j].pos != s[i].pos) j = i;
        if (s[i].type == 0) start[s[i].id] = j;
    }
    for (int i = n * 2, j = n * 2; i >= 1; i--) {
        if (s[j].pos != s[i].pos) j = i;
        if (s[i].type) end[s[i].id] = j;
    }
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int i = 1; i <= n * 2; i++) end_count[i] = end_count[i - 1] + s[i].type;
    for (int i = 1; i <= n; i++) ans[i] += end_count[end[i]] - end_count[start[i] - 1];
    start_count[n * 2 + 1] = 0;
    for (int i = n * 2; i >= 1; i--) start_count[i] = start_count[i + 1] + (s[i].type == 0);
    for (int i = 1; i <= n; i++) ans[i] += start_count[start[i]] - start_count[end[i] + 1];
    for (int i = 1; i <= n * 2; i++) ft[i] = 0;
    for (int i = n * 2, j = n * 2; i >= 1; i--) {
        while ((j) && (s[j].pos >= s[i].pos)) {
            if (s[j].type == 0) update(end[s[j].id]);
            j--;
        }
        if (s[i].type == 0) {
            ans[s[i].id] -= get(end[s[i].id]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (ans[i] > res) res = ans[i];
    res = n - res;
    printf("%d\n", res);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}