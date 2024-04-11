#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int f[200001];
bool in[200001];
int rem[200001];
int cnt;
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
    for (int i = 1; i <= n; i++) in[i] = 0;
    for (int i = 1; i <= n; i++)
        if (f[i]) in[f[i]] = 1;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!in[i]) rem[++cnt] = i;
    if (cnt > 2)
        for (int i = 1; i <= n; i++) {
            if (f[i] == 0) {
                if (i == rem[cnt]) {
                    rem[cnt] ^= rem[cnt - 1];
                    rem[cnt - 1] ^= rem[cnt];
                    rem[cnt] ^= rem[cnt - 1];
                }
                f[i] = rem[cnt--];
                if (cnt == 2) break;
            }
        }

    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;
        if (x == 0) x = i;
        else if (y == 0) y = i;
        else assert(false);
    }
    assert(cnt >= 2);
    int a = rem[1];
    int b = rem[2];
    if ((x == a) || (y == b)) {
        f[x] = b;
        f[y] = a;
    } else {
        f[x] = a;
        f[y] = b;
    }
    for (int i = 1; i <= n; i++) printf("%d ", f[i]);
    printf("\n");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}