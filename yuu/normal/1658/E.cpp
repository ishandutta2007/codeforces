#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<tuple<int, int, int>> order;
bool bad[2001][2001];
void solve() {
    cin >> n >> k;
    for (int i = 1, v; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> v;
            order.emplace_back(v, i, j);
        }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    auto get = [](int a, int b) {
        if (a == 0) return b;
        return -b;
    };

    int best[2][2];
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            best[a][b] = -1e9;
        }
    }
    for (auto&& [x, i, j] : order) {
        int best_dist = 0;
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                best_dist = max(best_dist, get(a, i) + get(b, j) + best[a][b]);
            }
        }
        if (best_dist > k) {
            bad[i][j] = true;
        } else {
            for (int a = 0; a <= 1; a++)
                for (int b = 0; b <= 1; b++) best[a][b] = max(best[a][b], -get(a, i) - get(b, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << "MG"[bad[i][j]];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}