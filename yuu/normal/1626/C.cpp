#include <bits/stdc++.h>
using namespace std;
int n;
int64_t h[101];
int64_t k[101];
int64_t req[101];
vector<pair<int64_t, int64_t>> ranges;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) req[i] = k[i] - h[i] + 1;
    for (int i = n - 1; i >= 1; i--) req[i] = min(req[i], req[i + 1]);
    ranges.clear();
    for (int i = 1; i <= n; i++)
        if (ranges.empty() || ranges.back().second < req[i])
            ranges.emplace_back(req[i], k[i]);
        else
            ranges.back().second = k[i];
    int64_t ans = 0;
    for (auto&& [l, r] : ranges) {
        int64_t val = r - l + 1;
        ans += val * (val + 1) / 2;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}