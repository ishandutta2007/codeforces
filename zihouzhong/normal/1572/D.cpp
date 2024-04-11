#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20, maxV = 20000;
int n, K, tot, cnt, ans, a[maxn], id[maxn];
int dist[maxV], pre[maxV], head[maxV], inq[maxV];
vector<array<int, 3>> cand;
queue<int> Q;
struct edge { int to, cap, cost, nxt; } e[100000];

void add(int u, int v, int cap, int cost) {
    e[cnt] = (edge){v, cap, cost, head[u]}, head[u] = cnt++;
    e[cnt] = (edge){u, 0, -cost, head[v]}, head[v] = cnt++;
}

bool spfa(int s, int t) {
    fill(dist, dist + t + 1, INT_MIN);
    Q.push(s), dist[s] = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(), inq[v] = 0;
        for (int i = head[v]; ~i; i = e[i].nxt) {
            if (e[i].cap && dist[e[i].to] < dist[v] + e[i].cost) {
                dist[e[i].to] = dist[v] + e[i].cost, pre[e[i].to] = i;
                if (!inq[e[i].to]) Q.push(e[i].to), inq[e[i].to] = 1;
            }
        }
    }
    return dist[t] > INT_MIN;
}

void upd(int s, int t) {
    for (int i = t; i ^ s; i = e[pre[i] ^ 1].to) {
        e[pre[i]].cap--, e[pre[i] ^ 1].cap++;
    }
    ans += dist[t];
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < 1 << n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            int k = i ^ (1 << j);
            if (i < k) cand.push_back({a[i] + a[k], i, k});
        }
    }
    int num = min((int)cand.size(), 2 * n * K);
    nth_element(cand.begin(), cand.begin() + num, cand.end(), greater<array<int, 3>>());
    for (int i = 0; i < num; i++) {
        if (!id[cand[i][1]]) id[cand[i][1]] = ++tot;
        if (!id[cand[i][2]]) id[cand[i][2]] = ++tot;
    }
    memset(head, -1, sizeof(head));
    int s = 0, t = tot + 1;
    for (int i = 0; i < 1 << n; i++) if (id[i]) {
        __builtin_parity(i) ? add(s, id[i], 1, a[i]) : add(id[i], t, 1, a[i]);
    }
    for (int i = 0; i < num; i++) {
        if (!__builtin_parity(cand[i][1])) swap(cand[i][1], cand[i][2]);
        add(id[cand[i][1]], id[cand[i][2]], 1, 0);
    }
    while (K-- && spfa(s, t)) upd(s, t);
    printf("%d\n", ans);
    return 0;
}