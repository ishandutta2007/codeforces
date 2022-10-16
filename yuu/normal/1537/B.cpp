#include <bits/stdc++.h>
using namespace std;
int64_t n, m, i, j;
int64_t get(pair<int64_t, int64_t> A, pair<int64_t, int64_t> B) {
    auto [x, y] = A;
    auto [s, t] = B;
    return abs(x - i) + abs(s - i) + abs(s - x) + abs(y - j) + abs(t - j) + abs(y - t);
}
void solve() {
    cin >> n >> m >> i >> j;
    pair<int64_t, pair<pair<int64_t, int64_t>, pair<int64_t, int64_t>>> ans = {-1, {{0, 0}, {0, 0}}};
    vector<pair<int64_t, int64_t>> pos = {{1, 1}, {1, m}, {n, 1}, {n, m}};
    for (int i = 0; i < pos.size(); i++)
        for (int j = 0; j < pos.size(); j++) ans = max(ans, {get(pos[i], pos[j]), {pos[i], pos[j]}});
    auto [x, y] = ans.second.first;
    auto [z, t] = ans.second.second;
    cout << x << ' ' << y << ' ' << z << ' ' << t << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}