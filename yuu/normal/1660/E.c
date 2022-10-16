#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char a[2000][2000];
void solve() {
    scanf("%d", &n);
    int total_1 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            while (a[i][j] = getchar())
                if (a[i][j] == '0' || a[i][j] == '1') break;
            total_1 += (a[i][j] == '1');
        }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int col = i;
        int cnt_1 = 0;
        for (int row = 0; row < n; row++) {
            cnt_1 += (a[row][col] == '1');
            col++;
            if (col == n) col = 0;
        }
        if (ans > total_1 - cnt_1 + n - cnt_1) ans = total_1 - cnt_1 + n - cnt_1;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}