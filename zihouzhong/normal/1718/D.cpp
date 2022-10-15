#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n), a(n);
    for (int &x : p) {
        cin >> x;
    }
    for (int &x : a) {
        cin >> x;
    }
    int k = count(a.begin(), a.end(), 0);
    vector<int> b(k - 1);
    for (int &x : b) {
        cin >> x;
    }
    vector<int> d(q);
    for (int &x : d) {
        cin >> x;
    }
    vector<int> l(n), r(n, INF);
    for (int i = 0; i < n; i++) {
        if (a[i]) l[i] = r[i] = a[i];
    }
    vector<int> lc(n, -1), rc(n, -1), s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && p[i] > p[s.back()]) {
            int x = s.back();
            rc[x] = lc[i], lc[i] = x;
            s.pop_back();
        }
        s.push_back(i);
    }    
    while (s.size() > 1) {
        int x = s.back();
        s.pop_back(), rc[s.back()] = x;
    }    
    function<void(int)> dfs = [&](int x) {
        for (int y : {lc[x], rc[x]}) if (~y) {
            r[y] = min(r[y], r[x]);
            dfs(y), l[x] = max(l[x], l[y]);
        }
    };
    dfs(s[0]);    
    bool flag = 1;
    vector<array<int, 2>> ranges;
    for (int i = 0; i < n; i++) {
        if (!a[i]) ranges.push_back({l[i], r[i]});
        if (l[i] > r[i]) flag = 0;
    }
    sort(ranges.begin(), ranges.end(), [&](auto a, auto b) {
        return a[1] < b[1];
    });    
    int L = -1, R = -1;
    set<int> S;
    for (int i = 0; i < k - 1; i++) {
        S.insert(b[i]);
    }
    for (auto [l, r] : ranges) {
        auto it = S.lower_bound(l);
        if (it == S.end() || *it > r) {
            if (R == -1) {
                R = r;
            } else {
                flag = false;
            }
        } else {
            S.erase(it);
        }
    }    
    sort(ranges.begin(), ranges.end(), greater<>());    
    S.clear();
    for (int i = 0; i < k - 1; i++) {
        S.insert(b[i]);
    }
    for (auto [l, r] : ranges) {
        auto it = S.upper_bound(r);
        if (it == S.begin() || *prev(it) < l) {
            if (L == -1) {
                L = l;
            } else {
                flag = false;
            }
        } else {
            S.erase(prev(it));
        }
    }    
    for (int i = 0; i < q; i++) {
        if (flag && L <= d[i] && d[i] <= R) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}