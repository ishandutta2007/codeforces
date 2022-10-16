#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct string_t {
    char data[101];
    int len;
} s[101], buffer[101];

bool compare(int i, int j) { return s[i].len < s[j].len; }

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (compare(x, y)) buffer[pos++] = s[x++];
        else buffer[pos++] = s[y++];
    }
    while (x <= m) buffer[pos++] = s[x++];
    while (y <= r) buffer[pos++] = s[y++];
    for (int i = l; i <= r; i++) s[i] = buffer[i - l];
}

bool check(int u) {
    // check if s[u] is substring of s[u + 1]
    for (int i = 0; i < s[u + 1].len; i++) {
        if (i + s[u].len > s[u + 1].len) break;
        for (int j = 0; j < s[u].len; j++)
            if (s[u].data[j] != s[u + 1].data[i + j]) goto next_i;
        return true;
    next_i:;
    }
    return false;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i].data);
        s[i].len = strlen(s[i].data);
    }
    merge_sort(1, n);
    for (int i = 1; i < n; i++) {
        if (!check(i)) {
            puts("NO");
            return;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) puts(s[i].data);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}