#include <bits/stdc++.h>
using namespace std;
int q;
int a[300001];
int c[300001];
int f[300001][19];
void solve() {
    cin >> q >> a[0] >> c[0];
    vector<pair<int, int>> stack;
    for (int i = 1, t, v, w; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> f[i][0] >> a[i] >> c[i];
            for (int j = 0; f[f[i][j]][j]; j++) f[i][j + 1] = f[f[i][j]][j];
        } else {
            stack.clear();
            cin >> v >> w;
            stack.emplace_back(v, 19);
            int64_t ans_buy = 0;
            int64_t ans_cost = 0;
            while ((!stack.empty()) && (w > 0)) {
                for (int i = stack.back().second - 1; i >= 0; i--) {
                    if (a[f[stack.back().first][i]]) {
                        stack.emplace_back(f[stack.back().first][i], i);
                    }
                }
                int64_t buy = min(w, a[stack.back().first]);
                ans_buy += buy;
                ans_cost += buy * c[stack.back().first];
                w -= buy;
                a[stack.back().first] -= buy;
                stack.pop_back();
            }
            cout << ans_buy << ' ' << ans_cost << '\n';
            cout.flush();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}