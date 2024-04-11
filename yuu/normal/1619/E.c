#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int n;
int cnt[200001];
int stk[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }
    int64_t cost = 0;
    int s = 0;
    bool bad = false;
    for (int i = 0; i <= n; i++) {
        if (bad) {
            printf("-1 ");
            continue;
        }
        printf("%lld ", cost + cnt[i]);
        for (int j = 0; j < cnt[i]; j++) {
            stk[s++] = i;
        }
        if (s == 0) {
            bad = true;
            continue;
        } else {
            cost += i - stk[--s];
        }
    }
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}