#include <bits/stdc++.h>
using namespace std;
int r[800001];
int x[200001];
int y[200001];
#define L(i) (i)
#define R(i) (i + n)
#define IJ(edge) (edge + n + n)
#define JI(edge) (edge + n + n + m)

int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) swap(u, v);
    r[u] += r[v];
    r[v] = u;
}

vector<int> g[200001];
vector<int> groups[800001];
char ori[200001];
bool done[800001];
vector<int> order;
int visited[200001];
int pos[200001];
int n, m;
void dfs(int u) {
    visited[u] = 1;
    for (int v : g[u]) {
        if (visited[v] == 1) {
            cout << "NO\n";
            exit(0);
        } else if (!visited[v])
            dfs(v);
    }
    visited[u] = 2;
    order.push_back(u);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n + n + m + m; i++) r[i] = -1;
    for (int i = 1, type; i <= m; i++) {
        cin >> type >> x[i] >> y[i];
        if (type == 1) {
            unite(L(x[i]), R(y[i]));
            unite(L(x[i]), IJ(i));

            unite(R(x[i]), L(y[i]));
            unite(R(x[i]), JI(i));
        } else {
            unite(R(x[i]), L(y[i]));
            unite(R(x[i]), IJ(i));

            unite(L(x[i]), R(y[i]));
            unite(L(x[i]), JI(i));
        }
    }
    for (int i = 1; i <= n; i++)
        if (root(L(i)) == root(R(i))) {
            cout << "NO\n";
            return;
        }
    for (int i = 1; i <= m; i++)
        if (root(IJ(i)) == root(JI(i))) {
            cout << "NO\n";
            return;
        }
    for (int i = 1; i <= n + n + m + m; i++) {
        groups[root(i)].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if ((!done[root(L(i))]) && (!done[root(R(i))])) {
            done[root(L(i))] = done[root(R(i))] = 1;
            for (auto&& thing : groups[root(L(i))]) {
                // cerr << thing << '\n';
                if (thing <= n)
                    ori[thing] = 'L';
                else if (thing <= n + n)
                    ori[thing - n] = 'R';
                else if (thing <= n + n + m)
                    g[x[thing - n - n]].push_back(y[thing - n - n]);
                else
                    g[y[thing - m - n - n]].push_back(x[thing - m - n - n]);
            }
        }

    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs(i);
    int cnt = 0;
    reverse(order.begin(), order.end());
    for (auto&& v : order) pos[v] = ++cnt;
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << ori[i] << ' ' << pos[i] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >>t;
    while (t--) solve();
}