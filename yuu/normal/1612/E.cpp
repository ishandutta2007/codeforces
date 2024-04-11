#include <bits/stdc++.h>
using namespace std;
int n;
int m[200001];
int k[200001];
int w[200001];
int64_t ans[200001];
multiset<pair<int, int>> best_set[21];
vector<int> best;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> m[i] >> k[i];
    for (int use = 1; use <= 20; use++) {
        for (int i = 1; i <= 200000; i++) w[i] = 0;
        for (int i = 1; i <= n; i++) w[m[i]] += min(k[i], use);
        for (int i = 1; i <= 200000; i++) {
            best_set[use].insert({w[i], i});
            if (best_set[use].size() > use) best_set[use].erase(best_set[use].begin());
        }
        for (auto &&[w, i] : best_set[use]) ans[use] += w;
    }

    for (int i = 1; i <= 200000; i++) best.push_back(i);
    sort(best.begin(), best.end(), [](const int &a, const int &b) { return w[a] > w[b]; });
    int64_t sum = 0;
    int cnt = 0;
    for (auto &&i : best) {
        sum += w[i];
        cnt++;
        if (cnt > 20) ans[cnt] = sum;
    }
    int best_pin = 1;
    for (int i = 2; i <= n; i++) {
        if (ans[i] * best_pin > ans[best_pin] * i) {
            best_pin = i;
        }
    }
    cout << best_pin << '\n';
    if (best_pin <= 20) {
        for (auto &&[t, x] : best_set[best_pin]) cout << x << ' ';
    } else {
        for (int i = 0; i < best_pin; i++) cout << best[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}