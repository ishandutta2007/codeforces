#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
struct Player {
    int a, id;
} p[200001], buffer[200001];

bool win[200001];
void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (p[x].a <= p[y].a) buffer[pos++] = p[x++];
        else buffer[pos++] = p[y++];
    }
    while (x <= m) {
        buffer[pos++] = p[x++];
    }
    while (y <= r) {
        buffer[pos++] = p[y++];
    }
    for (int i = l; i <= r; i++) p[i] = buffer[i - l];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].a);
        p[i].id = i;
    }
    merge_sort(1, n);
    win[p[n].id] = 1;
    int64_t total = 0;
    for (int i = 1; i < n; i++) total += p[i].a;
    for (int i = n - 1; i >= 1; i--) {
        if (p[i].a == p[i + 1].a) {
            win[p[i].id] = win[p[i + 1].id];
        } else {
            win[p[i].id] = (total >= p[i + 1].a) && (win[p[i + 1].id]);
        }
        total -= p[i].a;
    }
    int win_count = 0;
    for (int i = 1; i <= n; i++)
        if (win[i]) win_count++;
    printf("%d\n", win_count);
    for (int i = 1; i <= n; i++)
        if (win[i]) {
            printf("%d ", i);
        }
    printf("\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}