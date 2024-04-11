#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int &x : s) {
        cin >> x;
    }
    if (k == 1) {
        cout << "YES\n"; return;
    }
    adjacent_difference(s.begin(), s.end(), s.begin());
    if (!is_sorted(s.begin() + 1, s.end())) {
        cout << "NO\n"; return;
    }
    if (s[0] <= 1LL * s[1] * (n - k + 1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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