#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, l, r, sum;
int a[501];
bool done[501];
void solve() {
    scanf("%d %d %d %d", &n, &l, &r, &sum);
    int m = r - l + 1;
    int64_t low_sum = 0, high_sum = 0;
    for (int i = 1; i <= m; i++) {
        low_sum += i;
        high_sum += n - i + 1;
    }
    if ((sum < low_sum) || (sum > high_sum)) {
        printf("-1\n");
        return;
    }
    {
        int i = 1;
        while (low_sum < sum) {
            low_sum -= i;
            low_sum += m + i;
            i++;
        }
        assert(low_sum >= sum);
        for (int j = l; j <= r; j++) a[j] = i + j - l;
        for (int j = l; j <= r; j++) {
            int low = j - l + 1;
            int move = a[j] - low;
            if (low_sum - sum < move) move = low_sum - sum;
            a[j] -= move;
            low_sum -= move;
            if (low_sum == sum) break;
        }
        assert(low_sum == sum);
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = l; i <= r; i++) done[a[i]] = 1;
    int res = 1;
    for (int i = 1; i < l; i++) {
        while (done[res]) res++;
        a[i] = res;
        done[res] = 1;
    }
    for (int i = r + 1; i <= n; i++) {
        while (done[res]) res++;
        a[i] = res;
        done[res] = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}