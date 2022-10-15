#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int T, n, p[maxn], q[maxn], r[maxn], fa[maxn];
bool vis[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i], q[p[i]] = i;
        }
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fa[find(i)] = find(q[i]);
        }
        set<int> S;
        for (int i = 1; i <= n; i++) {
            r[i] = q[i], S.insert(i);
        }
        fill(vis + 1, vis + n + 1, 0);
        auto solve = [&](auto self, int x) -> bool {
            if (vis[x]) {
                return accumulate(vis + 1, vis + n + 1, 0) == n;
            }
            vis[x] = 1;
            pair<int, int> mn{INT_MAX, -1};
            set<int> T = {find(x)};
            for (auto it = S.lower_bound(x); it != S.begin() && !T.count(find(*--it)); ) {
                T.insert(find(*it));
                mn = min(mn, make_pair(r[*it], *it));
            }
            T = {find(x)};
            for (auto it = S.lower_bound(x); ++it != S.end() && !T.count(find(*it)); ) {
                T.insert(find(*it));
                mn = min(mn, make_pair(r[*it], *it));
            }
            if (mn.first > r[x] && self(self, r[x])) return 1;
            if (mn.first < INT_MAX) {
                int d[maxn], p[maxn];
                copy(r + 1, r + n + 1, d + 1);
                copy(fa + 1, fa + n + 1, p + 1);
                if (mn.second < x) {
                    for (auto it = S.lower_bound(mn.second); *it != x; it++) {
                        swap(r[*it], r[*next(it)]), fa[find(*it)] = find(*next(it));
                    }
                } else {
                    for (auto it = S.lower_bound(mn.second); *it != x; it--) {
                        swap(r[*it], r[*prev(it)]), fa[find(*it)] = find(*prev(it));
                    }
                }
                S.erase(x);
                if (self(self, r[x])) return 1;
                S.insert(x);
                swap(d, r), swap(p, fa);
            }
            return vis[x] = 0;
        };
        solve(solve, 1);
        for (int i = 1, j = 1; i <= n; i++) {
            cout << j << " ", j = r[j];
        }
        cout << "\n";
    }
    return 0;
}