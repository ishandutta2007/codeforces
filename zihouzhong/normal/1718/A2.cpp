#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<int> f(n + 1, INT_MAX);
    f[0] = 0;
    int pre = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(pre)) mp[pre] = INT_MAX;
        mp[pre] = min(mp[pre], f[i] - i);
        f[i + 1] = min(f[i + 1], f[i] + (a[i] > 0));
        pre ^= a[i];
        if (mp.count(pre)) f[i + 1] = min(f[i + 1], mp[pre] + i);
    }
    cout << f[n] << "\n";
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