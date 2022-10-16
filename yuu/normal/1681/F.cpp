#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> g[500001];
bool done[500001];
int h[500001];
vector<int> same[500001];
int first[500001];
int last[500001];
int low[500001];
int cnt;
void dfs(int u) {
    done[u] = 1;
    cnt++;
    first[u] = cnt;
    for (auto&& e : g[u])
        if (done[e.first]) {
            swap(e, g[u].back());
            g[u].pop_back();
            break;
        }
    for (auto&& [v, x] : g[u]) {
        same[x].push_back(v);
        h[v] = h[u] + 1;
        dfs(v);
    }
    last[u] = cnt;
}

class SegmentTree {
public:
    SegmentTree *left, *right;
    int l, r, m;
    int covered = 0;
    int weight = 0;

    SegmentTree(int l, int r) : l(l), r(r), m((l + r) / 2), covered(0), weight(0) {
        if (l == r) {
            weight = 1;
        } else {
            left = new SegmentTree(l, m);
            right = new SegmentTree(m + 1, r);
            weight = left->weight + right->weight;
        }
    }

    void update(int u, int v, int dc) {
        if (l > v || r < u) return;
        if ((u <= l) && (v >= r)) {
            covered += dc;
        } else {
            left->update(u, v, dc);
            right->update(u, v, dc);
        }
        if (covered) weight = 0;
        else if (l == r) weight = 1;
        else weight = left->weight + right->weight;
    }

    int get(int u, int v) {
        if (l > v || r < u) return 0;
        if ((u <= l) && (v >= r)) return weight;
        else {
            return left->get(u, v) + right->get(u, v);
        }
    }
};

void solve() {
    cin >> n;
    for (int i = 1, u, v, x; i < n; i++) {
        cin >> u >> v >> x;
        g[u].emplace_back(v, x);
        g[v].emplace_back(u, x);
    }
    dfs(1);
    int64_t ans = 0;
    SegmentTree* tree = new SegmentTree(1, n);
    for (int i = 1; i <= n; i++) {
        if (same[i].empty()) continue;
        sort(same[i].begin(), same[i].end(), [](const int& a, const int& b) { return h[a] > h[b]; });
        set<pair<int, int>> waiting;
        for (auto&& v : same[i]) {
            low[v] = tree->get(first[v], last[v]);
            while (!waiting.empty()) {
                auto it = waiting.upper_bound({first[v], 0});
                if (it == waiting.end()) break;
                if (it->first > last[v]) break;
                int u = it->second;
                ans += static_cast<int64_t>(low[v]) * (low[u]);
                waiting.erase(it);
            }
            waiting.insert({first[v], v});
            tree->update(first[v], last[v], 1);
        }
        for (auto&& [pos, v] : waiting) {
            ans += static_cast<int64_t>(tree->get(1, n)) * low[v];
        }
        for (auto&& v : same[i]) tree->update(first[v], last[v], -1);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}