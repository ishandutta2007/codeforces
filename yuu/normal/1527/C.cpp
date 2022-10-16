#include <bits/stdc++.h>
using namespace std;
int n;
map<int, vector<int>> m;
int64_t get(const vector<int>& pos) {
    int64_t res = 0;
    int64_t weight = 0;
    for (auto&& i : pos) {
        res += weight * (n - i + 1);
        weight += i;
    }
    return res;
}
void solve() {
    cin >> n;
    m.clear();
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        m[a].push_back(i);
    }
    int64_t ans = 0;
    for (auto&& [key, value] : m) ans += get(value);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}