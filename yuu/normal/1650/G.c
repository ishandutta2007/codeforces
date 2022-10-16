#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, s, t;
int fs[200001];

int deg[200001];
int u[200001];
int v[200001];
int next[400001];
int first[400001];
int last[400001];

int queue[200001];
int head, tail;

void queue_clear() {
    head = 1;
    tail = 0;
}

void queue_push(int u) { queue[++tail] = u; }

int queue_pop() { return queue[head++]; }

bool queue_empty() { return head > tail; }
void bfs(int start, int* dist) {
    queue_clear();
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
    dist[start] = 0;
    queue_push(start);
    while (!queue_empty()) {
        int u = queue_pop();
        for (int i = first[u]; i <= last[u]; i++) {
            int v = next[i];
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                queue_push(v);
            }
        }
    }
}

const int base = 1e9 + 7;
bool done[200001][2];
int ans[200001][2];

int get(int u, int b) {
    if (done[u][b]) return ans[u][b];
    done[u][b] = 1;
    if (u == s) {
        return ans[u][b] = 1;
    } else {
        ans[u][b] = 0;
        for (int i = first[u], v; i <= last[u]; i++) {
            v = next[i];
            if (fs[v] == fs[u] - 1) {
                ans[u][b] += get(v, b);
                if (ans[u][b] >= base) ans[u][b] -= base;
            }
        }
        if (b == 0) {
            for (int i = first[u], v; i <= last[u]; i++) {
                v = next[i];
                if (fs[v] == fs[u]) {
                    ans[u][b] += get(v, 1);
                    if (ans[u][b] >= base) ans[u][b] -= base;
                }
            }
        }
        return ans[u][b];
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        deg[u[i]]++;
        deg[v[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        first[i] = first[i - 1] + deg[i - 1];
        last[i] = first[i] - 1;
        // fprintf(stderr, "first[%d] = %d\n", i, first[i]);
    }
    for (int i = 1; i <= m; i++) {
        next[++last[u[i]]] = v[i];
        next[++last[v[i]]] = u[i];
    }
    bfs(s, fs);
    for (int i = 1; i <= n; i++) {
        done[i][0] = done[i][1] = 0;
    }
    printf("%d\n", get(t, 0));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}