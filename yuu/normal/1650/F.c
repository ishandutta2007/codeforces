#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int a[100001];
int dp[100001][101];
int trace[100001][101];
typedef struct Task {
    int e, t, p, id;
};
struct Task task[100001];

int sort_by_e(const void* A, const void* B) { return ((struct Task*)A)->e - ((struct Task*)B)->e; }
int current_task;
int current_time;
const int inf = 1e9 + 7;
int k;
int ans[100001];
bool process(int l, int r) {
    current_task++;
    if (task[l].e != current_task) return false;
    for (int j = 1; j <= 100; j++) dp[l - 1][j] = inf;
    dp[l - 1][0] = 0;
    for (int i = l; i <= r; i++) {
        for (int j = 0; j <= 100; j++) dp[i][j] = dp[i - 1][j];
        for (int j = 0; j <= 100; j++) trace[i][j] = j;
        for (int j = 0; j < 100; j++)
            if (dp[i - 1][j] != inf) {
                int new_j = j + task[i].p;
                if (new_j > 100) new_j = 100;
                if (dp[i][new_j] > dp[i - 1][j] + task[i].t) {
                    dp[i][new_j] = dp[i - 1][j] + task[i].t;
                    trace[i][new_j] = j;
                }
            }
    }

    current_time += dp[r][100];
    if (current_time > a[current_task]) return false;
    int p = 100;
    while (r >= l) {
        if (trace[r][p] != p) {
            ans[++k] = task[r].id;
            p = trace[r][p];
        }
        r--;
    }
    return true;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &task[i].e, &task[i].t, &task[i].p);
        task[i].id = i;
    }
    qsort(&task[1], m, sizeof(struct Task), sort_by_e);
    current_task = current_time = k = 0;
    for (int i = 1; i <= m; i++) {
        int j = i;
        while ((j + 1 <= m) && (task[j + 1].e == task[j].e)) j++;
        if (!process(i, j)) {
            printf("-1\n");
            return;
        }
        i = j;
    }
    if (current_task != n) {
        printf("-1\n");
        return;
    }
    printf("%d\n", k);
    for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}