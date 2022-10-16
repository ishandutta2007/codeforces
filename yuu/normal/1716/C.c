#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m;
int a[400000][2];
int snake[200000][2];
int pipe[400000][2];
void solve() {
    scanf("%d", &m);
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[j][i]);
    snake[0][0] = 0;
    snake[0][1] = 1;
    if (snake[0][1] <= a[0][1]) snake[0][1] = a[0][1] + 1;
    for (int i = 1; i < m; i++) {
        if (i % 2) {
            snake[i][1] = snake[i - 1][1] + 1;
            if (snake[i][1] < a[i][1] + 1) snake[i][1] = a[i][1] + 1;
            snake[i][0] = snake[i][1] + 1;
            if (snake[i][0] < a[i][0] + 1) snake[i][0] = a[i][0] + 1;
        } else {
            snake[i][0] = snake[i - 1][0] + 1;
            if (snake[i][0] < a[i][0] + 1) snake[i][0] = a[i][0] + 1;
            snake[i][1] = snake[i][0] + 1;
            if (snake[i][1] < a[i][1] + 1) snake[i][1] = a[i][1] + 1;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++) a[m + i][1 - j] = a[m - i - 1][j];
    pipe[0][0] = 0;
    pipe[0][1] = a[0][1] + 1;
    for (int i = 1; i < m * 2; i++) {
        for (int j = 0; j < 2; j++) {
            pipe[i][j] = pipe[i - 1][j] + 1;
            if (pipe[i][j] < a[i][j] + 1) pipe[i][j] = a[i][j] + 1;
        }
        // printf("%d %d %d %d\n", a[i][0], a[i][1], pipe[i][0], pipe[i][1]);
    }
    int ans = 2e9;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            int done = i * 2 + 1;
            if (i % 2 != j) done++;
            int required_pipe = i + m * 2 - done;
            int res = pipe[required_pipe][j];
            if (res < snake[i][j] + m * 2 - done) res = snake[i][j] + m * 2 - done;
            if (ans > res) ans = res;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}