// Assume that anything bigger than a square cannot be coloured
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> g[1 << 16];
vector<int> cross_edge[1 << 16];
int a[1 << 16];
int b[1 << 16];
int done[1 << 16];
int cnt;

queue<int> q;
int bfs(int u, int* dist) {
    cnt++;
    dist[u] = 0;
    done[u] = cnt;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : g[u])
            if (done[v] != cnt) {
                done[v] = cnt;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    return u;
}

int id[1 << 16];
bool side[1 << 16];
int color[1 << 16];
void make_permutation(int l, int r) {
    if (l + 1 == r) {
        return;
    }

    int self = id[l];
    int other_near = g[self][0];
    int other_far = bfs(self, a);
    bfs(other_near, a);
    int dist = a[other_far];
    bfs(other_far, b);
    for (int i = l; i <= r; i++) {
        if (a[id[i]] + b[id[i]] == dist) {
            side[id[i]] = 1;
        } else {
            side[id[i]] = 0;
        }
    }

    int our = l, their = r;
    while (our < their) {
        if (side[id[our]] == false)
            our++;
        else if (side[id[their]] == true)
            their--;
        else {
            swap(id[our], id[their]);
            our++;
            their--;
        }
    }
    our = r;
    their = l;
    while (side[id[our]]) our--;
    while (!side[id[their]]) their++;
    assert(our + 1 == their);

    for (int i = l; i <= our; i++) {
        for (auto&& x : g[id[i]]) {
            if (side[x]) {
                cross_edge[id[i]].push_back(x);
                swap(x, g[id[i]].back());
                g[id[i]].pop_back();
                break;
            }
        }
    }

    make_permutation(l, our);
    for (int i = l; i <= our; i++) {
        id[i + our - l + 1] = cross_edge[id[i]].back();
        cross_edge[id[i]].pop_back();
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) g[i].clear();
    for (int i = 0; i < (1 << n); i++) cross_edge[i].clear();
    for (int i = 0, u, v; i < (n << (n - 1)); i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < (1 << n); i++) id[i] = i;
    make_permutation(0, (1 << n) - 1);
    for (int i = 0; i < (1 << n); i++) cout << id[i] << " \n"[i + 1 == (1 << n)];
    if (n != (1 << __lg(n))) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < (1 << n); i++) {
            color[id[i]] = 0;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) color[id[i]] ^= j;
        }
        for (int i = 0; i < (1 << n); i++) cout << color[i] << " \n"[i + 1 == (1 << n)];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}