#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1001][1001];
bool done[1001][1001];
queue<pair<int, int>> q;
class Oper {
  public:
    int i, j, c;
};
vector<Oper> answer;
int check(const int& i, const int& j) {
    if (i == n || j == m) return 0;
    int now = a[i][j];
    for (int dx = 0; dx <= 1; dx++)
        for (int dy = (dx == 0); dy <= 1; dy++) {
            if (a[i + dx][j + dy] == now) continue;
            if (now == 0)
                now = a[i + dx][j + dy];
            else if (a[i + dx][j + dy])
                return 0;
        }
    return now;
}

void TryPaint(const int& i, const int& j) {
    if (done[i][j]) return;
    int c = check(i, j);
    if (c == 0) return;
    done[i][j] = 1;
    answer.push_back({i, j, c});
    for (int dx = 0; dx <= 1; dx++)
        for (int dy = 0; dy <= 1; dy++) a[i + dx][j + dy] = 0;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni < 1 || ni >= n) continue;
            if (nj < 1 || nj >= m) continue;
            if (done[ni][nj]) continue;
            q.push({ni, nj});
        }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) TryPaint(i, j);
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        TryPaint(i, j);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j]) {
                cout << "-1\n";
                return;
            }
    reverse(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto&& [i, j, c] : answer) cout << i << ' ' << j << ' ' << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}