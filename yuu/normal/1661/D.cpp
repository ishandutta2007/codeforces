#include <bits/stdc++.h>
using namespace std;
int n, k;
int64_t b[300001];

pair<int64_t, int64_t> ft[300001];
void update(int u, pair<int64_t, int64_t> diff) {
    for (; u <= n; u += (u & -u)) {
        ft[u].first += diff.first;
        ft[u].second += diff.second;
    }
}
pair<int64_t, int64_t> get(int u) {
    pair<int64_t, int64_t> res{0, 0};
    for (; u > 0; u -= (u & -u)) {
        res.first += ft[u].first;
        res.second += ft[u].second;
    }
    return res;
}

void Add(int l, int64_t count) {
    assert(l + k - 1 <= n);
    update(l, {count, -count * (l - 1)});
    update(l + k, {-count, count * (l - 1)});
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> b[i];
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        auto [x, y] = get(i);
        int64_t a = x * i + y;
        if (a >= b[i]) continue;
        int64_t weight = (b[i] - a - 1) / (min(i, k)) + 1;
        Add(max(1, i - k + 1), weight);
        ans += weight;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}