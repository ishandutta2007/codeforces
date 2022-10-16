#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m, q;
int count, inside, col, last_row;
char c[1001][1002];

void inc_count() {
    count++;
    col = count / n;
    last_row = count % n;
    if (last_row) {
        inside += (c[last_row][col + 1] == '*');
    } else {
        inside += (c[n][col] == '*');
    }
}

void dec_count() {
    if (last_row) {
        inside -= (c[last_row][col + 1] == '*');
    } else {
        inside -= (c[n][col] == '*');
    }
    count--;
    col = count / n;
    last_row = count % n;
}

void solve() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", c[i] + 1);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            count += (c[i][j] == '*');
        }
    col = count / n;
    last_row = count % n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '*') {
                inside += (j <= col) || ((j == col + 1) && (i <= last_row));
            }
        }
    }
    for (int i = 1, x, y; i <= q; i++) {
        scanf("%d %d", &x, &y);
        if (c[x][y] == '.') {
            inc_count();
            c[x][y] = '*';
            inside += (y <= col) || ((y == col + 1) && (x <= last_row));
        } else {
            dec_count();
            inside -= (y <= col) || ((y == col + 1) && (x <= last_row));
            c[x][y] = '.';
        }
        printf("%d\n", count - inside);
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}