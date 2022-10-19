#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    vector<int> sum(2 * n + 1);

    int val = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
        val = max(val, sum[i]);
    }

    vector<int> par(2 * n + 1);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int x) {
        if (x == par[x]) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    };

    map<int, int> last;
    for (int i = 2 * n; i; --i) {
        if (last[sum[i - 1]]) {
            par[i] = find(last[sum[i - 1]]);
        }
        last[sum[i]] = par[i];
        if (last.count(sum[i] + 1)) {
            last.erase(sum[i] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        ans += (find(i) == i);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}