#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[100];
bool done[100][100];
const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> order;
void dfs(int x, int y) {
    done[x][y] = 1;
    order.emplace_back(x, y);
    for (auto&& [dx, dy] : dir) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= n) continue;
        if (ny < 0 || ny >= m) continue;
        if (s[nx][ny] != '1') continue;
        if (!done[nx][ny]) dfs(nx, ny);
    }
}

bool check() {
    int low_x = 1e9, high_x = 0;
    int low_y = 1e9, high_y = 0;
    for (auto&& [x, y] : order) {
        low_x = min(low_x, x);
        high_x = max(high_x, x);
        low_y = min(low_y, y);
        high_y = max(high_y, y);
    }
    return (high_x - low_x + 1) * (high_y - low_y + 1) == order.size();
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) done[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((!done[i][j]) && (s[i][j] == '1')) {
                order.clear();
                dfs(i, j);
                if (!check()) {
                    cout << "NO\n";
                    return;
                }
            }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}