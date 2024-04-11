#include <bits/stdc++.h>
using namespace std;
int n, m, k, q;
class Point {
  public:
    int x, y;
} p[200001];
set<int> Sx, Sy;
set<pair<int, int>> Sxy;
void solve() {
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= q; i++) cin >> p[i].x >> p[i].y;
    Sx.clear();
    Sy.clear();
    Sxy.clear();
    int power = 0;
    for (int i = q; i >= 1; i--) {
        int x = p[i].x;
        int y = p[i].y;
        int total = 0;
        if (Sxy.find({x, y}) != Sxy.end()) continue;
        Sxy.insert({x, y});
        if (Sx.find(x) == Sx.end()) {
            Sx.insert(x);
            total += m - Sy.size();
        }
        if (Sy.find(y) == Sy.end()) {
            Sy.insert(y);
            total += n - Sx.size();
        }
        if (total) power++;
    }
    int64_t ans = 1;
    for (int i = 1; i <= power; i++) (ans *= k) %= 998'244'353;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}