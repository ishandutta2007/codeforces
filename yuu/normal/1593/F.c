#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, a, b;
char s[41];
struct {
    bool red;
    int old;
} trace[41][41][41][41];

void trace_back(int i, int j, int x, int y) {
    if (i == 0) return;
    if (trace[i][j][x][y].red) {
        trace_back(i - 1, j - 1, trace[i][j][x][y].old, y);
        printf("R");
    } else {
        trace_back(i - 1, j, x, trace[i][j][x][y].old);
        printf("B");
    }
}

void solve() {
    scanf("%d %d %d\n%s", &n, &a, &b, &s);
    for (int i = 0; i < n; i++) s[i] -= '0';
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int x = 0; x < a; x++)
                for (int y = 0; y < b; y++) trace[i][j][x][y].old = -1;
    trace[0][0][0][0].old = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = 0; x < a; x++) {
                for (int y = 0; y < b; y++) {
                    if (trace[i][j][x][y].old != -1) {
                        // red
                        int nx = (x * 10 + s[i]) % a;
                        if (trace[i + 1][j + 1][nx][y].old == -1) {
                            trace[i + 1][j + 1][nx][y].red = true;
                            trace[i + 1][j + 1][nx][y].old = x;
                        }

                        int ny = (y * 10 + s[i]) % b;
                        if (trace[i + 1][j][x][ny].old == -1) {
                            trace[i + 1][j][x][ny].red = false;
                            trace[i + 1][j][x][ny].old = y;
                        }
                        // printf("%d %d %d %d %d %d\n", i, j, x, y, nx, ny);
                    }
                }
            }
        }
    }
    int best_j = -1;
    for (int j = 1; j < n; j++) {
        if (trace[n][j][0][0].old != -1) {
            if (best_j == -1) {
                best_j = j;
            } else if (abs(n - best_j - best_j) > abs(n - j - j)) {
                best_j = j;
            }
        }
    }
    if (best_j == -1) {
        printf("-1\n");
        return;
    }
    trace_back(n, best_j, 0, 0);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}