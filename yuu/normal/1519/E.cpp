#include <bits/stdc++.h>
using namespace std;
class Fraction {
  public:
    __int128 x, y;
    Fraction(int64_t x, int64_t y = 1) {
        auto d = gcd(x, y);
        x /= d;
        y /= d;
        this->x = x;
        this->y = y;
    }

    Fraction AddOne() const {
        Fraction res = (*this);
        res.x += res.y;
        return res;
    }

    friend Fraction GetSlope(const Fraction& a, const Fraction& b) { return Fraction(a.x * b.y, a.y * b.x); }

    bool operator<(const Fraction& other) const { return x * other.y < y * other.x; }
};

map<Fraction, int> id;
vector<pair<int, int>> g[400001];
vector<int> avaiable[400001];
bool done[400001];
int ban[400001];
bool used[200001];
vector<pair<int, int>> ans;
void dfs(int u) {
    done[u] = 1;
    if (ban[u]) avaiable[u].push_back(ban[u]);
    for (auto&& [v, e] : g[u]) {
        if (!done[v]) {
            ban[v] = e;
            dfs(v);
            if (!used[e]) {
                avaiable[u].push_back(e);
            }
        } else if ((!used[e]) && (e != ban[u])) {
            avaiable[u].push_back(e);
        }
    }
    while (avaiable[u].size() >= 2) {
        ans.emplace_back(avaiable[u].back(), avaiable[u][avaiable[u].size() - 2]);
        used[avaiable[u].back()] = 1;
        avaiable[u].pop_back();
        used[avaiable[u].back()] = 1;
        avaiable[u].pop_back();
    }
    avaiable[u].clear();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1, a, b, c, d; i <= n; i++) {
        cin >> a >> b >> c >> d;
        Fraction x(a, b);
        Fraction y(c, d);

        auto up = GetSlope(x.AddOne(), y);
        auto right = GetSlope(x, y.AddOne());
        if (id.find(up) == id.end()) id[up] = id.size();
        if (id.find(right) == id.end()) id[right] = id.size();
        g[id[up]].emplace_back(id[right], i);
        g[id[right]].emplace_back(id[up], i);
    }
    for (int i = 1; i <= id.size(); i++)
        if (!done[i]) dfs(i);
    cout << ans.size() << '\n';
    for (auto&& [a, b] : ans) cout << a << ' ' << b << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}