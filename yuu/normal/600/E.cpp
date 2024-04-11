#include <bits/stdc++.h>
using namespace std;
int n;
int c[100001];
vector<int> g[100001];
class popular_set_t {
public:
    map<int, int> cnt;

    int high;
    int64_t sum;

    void merge(popular_set_t& other) {
        if (cnt.size() < other.cnt.size()) {
            other.merge(*this);
            cnt = std::move(other.cnt);
            high = other.high;
            sum = other.sum;
        } else {
            for (auto&& [item, count] : other.cnt) {
                auto&& stored = (cnt[item] += count);
                if (stored > high) {
                    high = stored;
                    sum = item;
                } else if (stored == high) {
                    sum += item;
                }
            }
        }
    }

    void init(int val) {
        cnt.clear();
        cnt[val] = 1;
        high = 1;
        sum = val;
    }
} p[100001];
bool done[100001];
int64_t ans[100001];
void dfs(int u) {
    done[u] = 1;
    p[u].init(c[u]);
    for (auto&& v : g[u])
        if (!done[v]) {
            dfs(v);
            p[u].merge(p[v]);
        }
    ans[u] = p[u].sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}