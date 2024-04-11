#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    map<int, long long> mp;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        mp[i - x] += x;
    }
    long long ans = 0;
    for (auto p: mp) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
}