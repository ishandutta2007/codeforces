#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct position_t {
    int x, y, id;
} p[200001], buffer[200001];
int n;
char s[200001];
bool smaller(int a, int b) {
    if (p[a].x != p[b].x) return p[a].x < p[b].x;
    if (p[a].y != p[b].y) return p[a].y < p[b].y;
    return p[a].id < p[b].id;
}
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (smaller(x, y)) buffer[pos++] = p[x++];
        else buffer[pos++] = p[y++];
    }
    while (x <= m) buffer[pos++] = p[x++];
    while (y <= r) buffer[pos++] = p[y++];
    for (int i = l; i <= r; i++) p[i] = buffer[i - l];
}

void solve() {
    scanf("%d", &n);
    scanf("%s", &s[1]);
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'R') {
            x++;
        } else if (s[i] == 'U') {
            y--;
        } else {
            y++;
        }
        p[i].x = x;
        p[i].y = y;
        p[i].id = i;
    }
    p[0].x = 0;
    p[0].y = 0;
    p[0].id = 0;
    merge_sort(0, n);
    int l = 0, r = 1e9;
    for (int i = 1; i <= n; i++) {
        if ((p[i].x == p[i - 1].x) && (p[i].y == p[i - 1].y)) {
            if (p[i].id - p[i - 1].id < r - l) {
                l = p[i - 1].id;
                r = p[i].id;
            }
        }
    }
    if (r == 1e9) {
        puts("-1");
        return;
    }
    printf("%d %d\n", l + 1, r);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}