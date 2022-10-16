#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200001];
bool done[200001];
pair<int, int64_t> f[200001][2];
int deg[200001];

int ans_count;
int64_t ans_sum;
bool special[200001];

pair<int, int64_t> best(const pair<int, int64_t> a, const pair<int, int64_t> b) {
    if (a.first > b.first)
        return a;
    else if (a.first < b.first)
        return b;
    else
        return min(a, b);
}

void dfs(int u) {
    done[u] = 1;
    deg[u] = g[u].size();
    for (auto&& v : g[u])
        if (done[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    f[u][0] = {0, 1};
    f[u][1] = {1, deg[u]};
    for (int v : g[u]) {
        dfs(v);
        f[u][1].first += f[v][0].first;
        f[u][1].second += f[v][0].second;

        auto b = best(f[v][0], f[v][1]);
        f[u][0].first += b.first;
        f[u][0].second += b.second;
    }
}

void construct(int u, bool b) {
    if (b) {
        special[u] = 1;
        ans_count += 1;
        ans_sum += deg[u];
        for (int v : g[u]) construct(v, 0);
    } else {
        ans_sum++;
        for (int v : g[u]) {
            construct(v, best(f[v][1], f[v][0]) == f[v][1]);
        }
    }
}

void solve() {
    cin >> n;
    if (n == 2) {
        cout << "2 2\n1 1\n";
        return;
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    construct(1, best(f[1][1], f[1][0]) == f[1][1]);
    cout << ans_count << ' ' << ans_sum << '\n';
    for (int i = 1; i <= n; i++) {
        if (special[i])
            cout << deg[i] << " \n"[i == n];
        else
            cout << 1 << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}