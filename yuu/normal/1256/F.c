#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[200001];
char t[200001];
int cnt[256];
void solve() {
    scanf("%d %s %s", &n, s, t);
    for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 0; i < n; i++) cnt[t[i]]--;
    for (int i = 'a'; i <= 'z'; i++)
        if (cnt[i]) {
            puts("NO");
            return;
        }
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 'a'; i <= 'z'; i++)
        if (cnt[i] > 1) {
            puts("YES");
            return;
        }
    int parity = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            parity += (s[j] < s[i]);
            parity -= (t[j] < t[i]);
        }
    if (parity % 2) puts("NO");
    else puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}