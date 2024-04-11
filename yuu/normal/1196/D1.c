#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
char s[200001];
int cnt[3][3];
int total[3];
void solve() {
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') s[i] = 0;
        else if (s[i] == 'G') s[i] = 1;
        else s[i] = 2;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cnt[i][j] = 0;
    int ans = k;
    for (int i = 0; i < n; i++) {
        cnt[i % 3][s[i]]++;
        if (i - k >= 0) cnt[(i - k) % 3][s[i - k]]--;
        if (i >= k - 1) {
            for (int shift = 0; shift < 3; shift++) {
                int result = k;
                for (int pos = 0; pos < 3; pos++) result -= cnt[pos][(pos + shift) % 3];
                if (ans > result) ans = result;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}