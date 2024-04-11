#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char c[400][401];
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", &c[i]);
    int low_x = n, high_x = -1, low_y = n, high_y = -1;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++) {
            if (c[x][y] == '*') {
                if (x < low_x) low_x = x;
                if (x > high_x) high_x = x;
                if (y < low_y) low_y = y;
                if (y > high_y) high_y = y;
            }
        }
    if ((low_x != high_x) && (low_y != high_y)) {
        c[low_x][low_y] = '*';
        c[low_x][high_y] = '*';
        c[high_x][low_y] = '*';
        c[high_x][high_y] = '*';
    } else if (low_x == high_x) {
        int other_x = (low_x == 0);
        c[other_x][low_y] = '*';
        c[other_x][high_y] = '*';
    } else {
        int other_y = (low_y == 0);
        c[low_x][other_y] = '*';
        c[high_x][other_y] = '*';
    }
    for (int i = 0; i < n; i++) printf("%s\n", c[i]);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}