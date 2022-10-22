#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x, x--;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] > a[i + 1]) v.emplace_back(a[i] - a[i + 1], i);
    }
    sort(v.begin(), v.end());
    vector<int> res(n);
    int p = 1;
    for (auto [x, i] : v) {
        p = max(p, x);
        res[p++] = i + 1;
    }
    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << "\n";
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