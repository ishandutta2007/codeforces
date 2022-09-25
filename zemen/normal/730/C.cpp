#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 5005;
vector<int> g[maxn];

struct Shop {
    int u, cnt, cost;

    bool operator<(const Shop &s) const {
        return cost < s.cost;
    }
};

vector<Shop> all;
int dist[maxn];
int n;

queue<int> o;
void bfs(int u) {
    forn (i, n)
        dist[i] = inf;
    dist[u] = 0;
    o.push(u);
    while (!o.empty()) {
        int u = o.front();
        o.pop();
        for (int v: g[u]) {
            if (dist[v] != inf)
                continue;
            dist[v] = dist[u] + 1; 
            o.push(v);
        }
    }
}

ll calc(int cnt, int bound) {
    int L = -1, R = n + 1;

    while (L + 1 < R) {
        int C = (L + R) / 2;
        
        ll total = 0;
        int rem = cnt;
        for (auto &s: all) {
            if (dist[s.u] > C)
                continue;
            if (rem <= s.cnt) {
                total += s.cost * ll(rem);
                rem = 0;
                break;
            }
            total += s.cost * ll(s.cnt);
            rem -= s.cnt;
        }
        if (total > bound || rem > 0)
            L = C;
        else
            R = C;
    }

    if (R == n + 1)
        return -1;
    return R;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int m;
    cin >> n >> m;
    forn (i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int w;
    cin >> w;
    forn (i, w) {
        int u, cnt, cost;
        cin >> u >> cnt >> cost;
        --u;
        all.push_back(Shop{u, cnt, cost});
    }
    sort(all.begin(), all.end());
    int q;
    cin >> q;
    forn (i, q) {
        int u, bound, cnt;
        cin >> u >> cnt >> bound;
        --u;
        bfs(u);
        cout << calc(cnt, bound) << '\n';
    }
}