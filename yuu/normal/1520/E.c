#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char s[1000001];
int pos[1000001];
int64_t get(int start_pos) {
    int64_t res = 0;
    for (int i = 0; i < m; i++) res += abs(pos[i] - (start_pos + i));
    return res;
}
bool check(int val) { return get(val) >= get(val + 1); }
void solve() {
    scanf("%d%s", &n, &s);
    m = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '*') pos[m++] = i;

    if ((m <= 1) || (m == n)) {
        printf("0\n");
        return;
    }
    int low = 0, high = n - m - 1, mid, res = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int64_t ans = get(res);
    int64_t ans_2 = get(res+1);
    if(ans > ans_2) ans = ans_2;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}