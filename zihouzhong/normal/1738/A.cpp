#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) {
        cin >> x;
    }
    for (int &x : b) {
        cin >> x;
    }
    long long ans = accumulate(b.begin(), b.end(), 0LL);
    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        (!a[i] ? l : r).push_back(b[i]);
    }
    sort(l.begin(), l.end(), greater());
    sort(r.begin(), r.end(), greater());
    vector<pair<int, int>> v1, v2;
    int p1 = 0, p2 = 0;
    auto _l = l;
    if (!l.empty()) _l.insert(_l.begin(), _l.back()), _l.pop_back();
    for (int i = 0; i < n; i++) {
        if (p1 < l.size() && (i % 2 == 0 || p2 == r.size())) v1.emplace_back(_l[p1++], 0);
        else v1.emplace_back(r[p2++], 1);
    }
    p1 = p2 = 0;
    auto _r = r;
    if (!r.empty()) _r.insert(_r.begin(), _r.back()), _r.pop_back();
    for (int i = 0; i < n; i++) {
        if (p1 < l.size() && (i % 2 == 1 || p2 == r.size())) v2.emplace_back(l[p1++], 0);
        else v2.emplace_back(_r[p2++], 1);
    }
    auto calc = [&](auto v) {
        long long s = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].second != v[i + 1].second) s += v[i + 1].first;
        }
        return s;
    };
    cout << ans + max(calc(v1), calc(v2)) << "\n";
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