#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int64_t x[100001];
vector<tuple<int, int>> top[100001];
vector<tuple<int, int, int>> bottom[100001];
int64_t f[100001];
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) top[i].clear();
    for (int i = 1; i <= n; i++) bottom[i].clear();
    for (int i = 1, a, b, c, d, h; i <= k; i++) {
        cin >> a >> b >> c >> d >> h;
        bottom[a].emplace_back(b, i, h);
        top[c].emplace_back(d, i);
    }
    for (int i = 1; i <= k; i++) f[i] = 1e18;
    top[1].emplace_back(1, 0);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        sort(bottom[i].begin(), bottom[i].end());
        sort(top[i].begin(), top[i].end());
        {
            int64_t best = 1e18;
            int t = 0;
            for (auto&& [pos, id, h] : bottom[i]) {
                while ((t < top[i].size()) && (get<0>(top[i][t]) <= pos)) {
                    auto&& [top_pos, top_id] = top[i][t];
                    best = min(best, f[top_id] - x[i] * top_pos);
                    t++;
                }
                f[id] = min(f[id], best + x[i] * pos - h);
            }
        }

        reverse(bottom[i].begin(), bottom[i].end());
        reverse(top[i].begin(), top[i].end());
        {
            int64_t best = 1e18;
            int t = 0;
            for (auto&& [pos, id, h] : bottom[i]) {
                while ((t < top[i].size()) && (get<0>(top[i][t]) >= pos)) {
                    auto&& [top_pos, top_id] = top[i][t];
                    best = min(best, f[top_id] + x[i] * top_pos);
                    t++;
                }
                f[id] = min(f[id], best - x[i] * pos - h);
            }
        }
    }
    int64_t ans = 1e17;
    for (auto&& [pos, id] : top[n]) ans = min(ans, f[id] + x[n] * abs(m - pos));
    if (ans != 1e17)
        cout << ans << '\n';
    else
        cout << "NO ESCAPE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}