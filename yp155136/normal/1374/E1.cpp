#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v[4];

int main () {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int t, a, b; cin >> t >> a >> b;
        v[a * 2 + b].push_back(t);
    }
    for (int i = 1; i <= 3; ++i) {
        sort(v[i].begin(), v[i].end());
    }
    if (v[3].size() + min(v[1].size(), v[2].size()) < k) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = (1ll << 60);
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        if (i < v[3].size()) {
            sum += v[3][i];
        }
    }
    for (int i = k, j = 0; i >= 0; --i, ++j) {
        if (i - 1 < (int)v[3].size() && j <= min(v[1].size(), v[2].size())) {
            ans = min(ans, sum);
        }
        if (i - 1 < v[3].size() && i - 1 >= 0) {
            sum -= v[3][i - 1];
        }
        if (0 <= j && j < min(v[1].size(), v[2].size())) {
            sum += v[1][j];
            sum += v[2][j];
        }
    }
    cout << ans << endl;
}