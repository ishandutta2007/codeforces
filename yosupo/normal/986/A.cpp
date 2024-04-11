#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    VV<int> a(k);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; x--;
        a[x].push_back(i);
    }
    VV<int> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    VV<int> dist(k, V<int>(n));
    for (int ph = 0; ph < k; ph++) {
        dist[ph] = V<int>(n, TEN(9));
        queue<int> q;
        for (int d: a[ph]) {
            dist[ph][d] = 0;
            q.push(d);
        }
        while (q.size()) {
            int p = q.front(); q.pop();
            for (int d: g[p]) {
                if (dist[ph][d] <= dist[ph][p]+1) continue;                
                dist[ph][d] = dist[ph][p]+1;
                q.push(d);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        V<int> buf(k);
        for (int j = 0; j < k; j++) buf[j] = dist[j][i];
        nth_element(begin(buf), begin(buf)+s, end(buf));
        int ans = 0;
        for (int j = 0; j < s; j++) ans += buf[j];
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}