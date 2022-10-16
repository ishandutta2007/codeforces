#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[101];
bool done[102];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) done[i] = 0;
    done[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (a[j] == i) {
                int x = j;
                while (!done[x]) {
                    a[x] ^= a[x - 1];
                    a[x - 1] ^= a[x];
                    a[x] ^= a[x - 1];
                    done[x] = 1;
                    x--;
                }
                done[x + 1] = 1;
                break;
            }
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}