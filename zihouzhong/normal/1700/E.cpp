#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j], a[i][j]--;
        }
    }    
    auto chk = [&](int x, int y) {
        if (a[x][y] == 0) return 1;
        if (x > 0 && a[x - 1][y] < a[x][y]) return 1;
        if (x < n - 1 && a[x + 1][y] < a[x][y]) return 1;
        if (y > 0 && a[x][y - 1] < a[x][y]) return 1;
        if (y < m - 1 && a[x][y + 1] < a[x][y]) return 1;
        return 0;
    };    
    auto neighbor = [&](int x0, int y0) {
        set<array<int, 2>> a;
        for (auto [dx, dy] : {array<int, 2>{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int x = x0 + dx, y = y0 + dy;
            if (x >= 0 && x < n && y >= 0 && y < m) a.insert({x, y});
        }
        return a;
    };    
    vector<array<int, 2>> bad;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!chk(i, j)) bad.push_back({i, j});
        }
    }    
    if (bad.empty()) {
        cout << "0\n";
        return 0;
    }    
    if (bad.size() > 5) {
        cout << "2\n";
        return 0;
    }    
    set<array<array<int, 2>, 2>> s;
    for (auto [x0, y0] : bad) {
        for (auto [x, y] : neighbor(x0, y0)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    bool good = 1;
                    for (auto [u, v] : bad) {
                        if (abs(u - x) + abs(v - y) > 1 && abs(u - i) + abs(v - j) > 1) {
                            good = 0;
                        }
                    }
                    swap(a[i][j], a[x][y]);
                    for (auto [x0, y0] : {array<int, 2>{i, j}, {x, y}}) {
                        for (auto [x, y] : neighbor(x0, y0)) {
                            if (!chk(x, y)) {
                                good = 0;
                            }
                        }
                    }
                    swap(a[i][j], a[x][y]);
                    if (good) {
                        if (array<int, 2>{x, y} < array<int, 2>{i, j}) {
                            s.insert({{{x, y}, {i, j}}});
                        } else {
                            s.insert({{{i, j}, {x, y}}});
                        }
                    }
                }
            }
        }
        break;
    }    
    if (!s.empty()) cout << "1 " << s.size() << "\n";
    else cout << "2\n";
    return 0;
}