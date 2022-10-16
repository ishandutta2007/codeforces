#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int n, m;
char c[2001][2001];
int state[2001][2001];
int f[2001][2001];
stack<pair<int, int>> s;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) state[i][j] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (state[i][j] == -1) {
                int u = i, v = j;
                while (state[u][v] == -1) {
                    state[u][v] = s.size();
                    s.push({u, v});
                    if (c[u][v] == 'L')
                        v--;
                    else if (c[u][v] == 'R')
                        v++;
                    else if (c[u][v] == 'U')
                        u--;
                    else
                        u++;
                    if ((u < 1) || (u > n) || (v < 1) || (v > m)) break;
                }
                int more;
                if ((u < 1) || (u > n) || (v < 1) || (v > m) || (state[u][v] == -2)) {
                    if ((u < 1) || (u > n) || (v < 1) || (v > m)) {
                        more = 0;
                    } else {
                        more = f[u][v];
                    }
                } else {  // currently visiting
                    more = s.size() - state[u][v];
                    while (s.size() > state[u][v]) {
                        f[s.top().first][s.top().second] = more;
                        state[s.top().first][s.top().second] = -2;
                        s.pop();
                    }
                }
                while (!s.empty()) {
                    f[s.top().first][s.top().second] = ++more;
                    state[s.top().first][s.top().second] = -2;
                    s.pop();
                }
            }
    int ans = -1, ans_i, ans_j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j] > ans) {
                ans = f[i][j];
                ans_i = i;
                ans_j = j;
            }
    cout << ans_i << ' ' << ans_j << ' ' << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}