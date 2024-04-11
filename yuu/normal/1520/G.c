#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define inf 1000000000

int n, m;
int64_t w;
int value[2001][2001];

int dist_a[2001][2001];
int dist_b[2001][2001];

struct {
    int x, y;
} queue[4000001];

int queue_head;
int queue_tail;
void queue_push(int x, int y) {
    queue_tail++;
    queue[queue_tail].x = x;
    queue[queue_tail].y = y;
}

void queue_pop(int* x, int* y) {
    *x = queue[queue_head].x;
    *y = queue[queue_head].y;
    queue_head++;
}

void queue_clear() {
    queue_head = 0;
    queue_tail = -1;
}
bool queue_empty() { return queue_head > queue_tail; }

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, int dist[2001][2001]) {
    queue_clear();
    queue_push(x, y);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) dist[i][j] = inf;
    dist[x][y] = 0;
    while (!queue_empty()) {
        queue_pop(&x, &y);
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx > n || xx < 1) continue;
            if (yy > m || yy < 1) continue;
            if (dist[xx][yy] != inf) continue;
            if (value[xx][yy] == -1) continue;
            dist[xx][yy] = dist[x][y] + 1;
            queue_push(xx, yy);
        }
    }
}

int64_t find_tp(int dist[2001][2001]) {
    int64_t res = 1e18;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (value[i][j] > 0) {
                if (dist[i][j] != inf) {
                    if (res > w * dist[i][j] + value[i][j]) res = w * dist[i][j] + value[i][j];
                }
            }
        }
    return res;
}

void solve() {
    scanf("%d %d %lld", &n, &m, &w);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &value[i][j]);
        }
    bfs(1, 1, dist_a);
    bfs(n, m, dist_b);
    int64_t ans = 1e18;
    if (dist_a[n][m] != inf) ans = w * dist_a[n][m];
    int64_t best_tp_a = 1e18;
    int64_t best_tp_b = 1e18;
    int64_t tp_res = find_tp(dist_a) + find_tp(dist_b);
    if (ans > tp_res) ans = tp_res;
    if (ans == 1e18) ans = -1;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}