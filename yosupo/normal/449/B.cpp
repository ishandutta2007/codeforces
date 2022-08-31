#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, int> T;
typedef long long ll;
const int MN = 100010;
vector<T> g[MN];
const ll INF = 1LL<<61;
ll dist[MN];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        ll u, v, x;
        cin >> u >> v >> x; u--; v--;
        g[u].push_back(T(v, x, 0));
        g[v].push_back(T(u, x, 0));
    }
    for (int i = 0; i < k; i++) {
        ll s, t;
        cin >> s >> t; s--;
        g[0].push_back(T(s, t, 1));
    }
    fill_n(dist, MN, INF);
    priority_queue<T, vector<T>, greater<T>> q;
    q.push(T(0, 0, 0));
    ll res = 0;
    while (!q.empty()) {
        T p = q.top(); q.pop();
        ll d, v; int f;
        tie(d, v, f) = p;
        if (dist[v] <= d) continue;
        dist[v] = d;
        if (f) res++;
        for (T pp: g[v]) {
            ll dd, vv; int ff;
            tie(vv, dd, ff) = pp;
            if (dist[v]+dd < dist[vv]) {
                q.push(T(dist[v]+dd, vv, ff));
            }
        }
    }
    cout << k-res << endl;
    return 0;
}