#include <stdbool.h>
#include <stdio.h>

int n;
int b[200001];
int p[200001];
int prev[200001];
int dist[200001];
int w[200001];
bool done[200001];

int Dist(int u) {
    if (done[u]) return dist[u];
    done[u] = 1;
    if (u == p[1]) {
        dist[u] = 0;
        return 0;
    }
    dist[u] = 1e9;
    int res = Dist(b[u]);
    int temp = Dist(prev[u]);
    if (temp > res) res = temp;
    dist[u] = res + 1;
    return dist[u];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    if (b[p[1]] != p[1]) {
        printf("-1\n");
        return;
    }
    for (int i = 2; i <= n; i++) prev[p[i]] = p[i - 1];
    for (int i = 1; i <= n; i++) done[i] = false;
    for (int i = 1; i <= n; i++) {
        int path = Dist(i);
        if (path >= 1e9) {
            printf("-1\n");
            return;
        }
        w[i] = path - Dist(b[i]);
    }
    for (int i = 1; i <= n; i++) printf("%d ", w[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}