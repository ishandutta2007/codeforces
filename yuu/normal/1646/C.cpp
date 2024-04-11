#include <bits/stdc++.h>
using namespace std;

vector<int64_t> facts;
vector<pair<int64_t, int>> pregen;

void backtrack(int u, int cnt, int64_t sum) {
    if (u == facts.size()) {
        pregen.emplace_back(sum, cnt);
    } else {
        backtrack(u + 1, cnt, sum);
        backtrack(u + 1, cnt + 1, sum + facts[u]);
    }
}

void prepare() {
    int64_t f = 2;
    for (int i = 3;; i++) {
        f *= i;
        if (f > 1'000'000'000'000) break;
        facts.push_back(f);
    }
    backtrack(0, 0, 0);
}

int64_t n;
void solve() {
    cin >> n;
    int ans = 1e9;
    for (auto&& [sum, cnt] : pregen) {
        if (sum > n) continue;
        ans = min(ans, cnt + popcount(uint64_t(n - sum)));
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    int t = 1;
    cin >> t;
    while (t--) solve();
}