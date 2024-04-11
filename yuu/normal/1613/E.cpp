#include <bits/stdc++.h>
using namespace std;

char buffer[1000000];
char* c[1000000];
int n, m;
queue<pair<int, int>> q;
const vector<pair<int, int>> dir({{1, 0}, {-1, 0}, {0, -1}, {0, 1}});
bool check(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (c[x][y] != '.') return false;
    int good_count = 0;
    int valid_count = 0;
    for (auto&& [dx, dy] : dir) {
        if (x + dx < 0 || x + dx >= n) continue;
        if (y + dy < 0 || y + dy >= m) continue;
        if (c[x + dx][y + dy] == '#') continue;
        valid_count++;
        if (c[x + dx][y + dy] == '+' || c[x + dx][y + dy] == 'L') good_count++;
    }
    if (good_count == 0) return false;
    return (good_count + 1) >= valid_count;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) c[i] = buffer + m * i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'L') q.push({i, j});
        }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto&& [dx, dy] : dir)
            if (check(x + dx, y + dy)) {
                c[x + dx][y + dy] = '+';
                q.push({x + dx, y + dy});
            }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << c[i][j];
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}