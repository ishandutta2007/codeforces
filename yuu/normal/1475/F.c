#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
char a[1000][1001];
char b[1000][1001];
int h[1000];
int v[1000];
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", &a[i]);
    for (int i = 0; i < n; i++) scanf("%s", &b[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) a[i][j] -= '0';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) b[i][j] -= '0';
    for (int p = 0; p <= 1; p++) {
        h[0] = p;
        for (int i = 0; i < n; i++) v[i] = b[0][i] ^ a[0][i] ^ h[0];
        for (int i = 0; i < n; i++) h[i] = b[i][0] ^ a[i][0] ^ v[0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (b[i][j] != (a[i][j] ^ h[i] ^ v[j])) {
                    goto next_p;
                }
        printf("YES\n");
        return;
    next_p:;
    }
    printf("NO\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}