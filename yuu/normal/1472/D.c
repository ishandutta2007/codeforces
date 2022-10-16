#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[200001];
int buffer[200001];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int t = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) buffer[t++] = a[x++];
        else buffer[t++] = a[y++];
    }
    while (x <= m) buffer[t++] = a[x++];
    while (y <= r) buffer[t++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    int turn = 0;
    int64_t score[2];
    score[0] = score[1] = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] % 2 == turn) {
            score[turn] += a[i];
        }
        turn = 1 - turn;
    }
    if (score[0] > score[1]) printf("Alice\n");
    else if (score[0] < score[1]) printf("Bob\n");
    else printf("Tie\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}