#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, p, q, prob;
map<tuple<int, int, int, int>, bool> states;
int64_t bad;

constexpr int64_t base = 1e9 + 7;

int64_t power(int64_t x, int64_t pow) {
    int64_t ans = 1;
    while (pow > 0) {
        if (pow % 2) (ans *= x) %= base;
        pow /= 2;
        (x *= x) %= base;
    }
    return ans;
}

int64_t inverse(int64_t x) { return power(x, base - 2); }

pair<int64_t, int64_t> solve(int cx, int cy, int dx, int dy) {
    if (states.find({cx, cy, dx, dy}) != states.end()) {
        states[{cx, cy, dx, dy}] = true;
        return {0, 1};
    }
    states[{cx, cy, dx, dy}] = false;
    int ndx = dx;
    int nx = cx + ndx;
    int ndy = dy;
    int ny = cy + ndy;
    if (nx > n || nx <= 0) {
        nx -= ndx * 2;
        ndx = -ndx;
    }
    if (ny > m || ny <= 0) {
        ny -= ndy * 2;
        ndy = -ndy;
    }
    auto res = solve(nx, ny, ndx, ndy);
    res.first += 1;

    if ((cx == p) || (cy == q)) {
        (res.first *= bad) %= base;
        (res.second *= bad) %= base;
    }

    if (states[{cx, cy, dx, dy}]) {
        return {(res.first * inverse(base + 1 - res.second)) % base, 0};
    } else {
        return res;
    }
}
void solve() {
    cin >> n >> m >> x >> y >> p >> q >> prob;
    states.clear();
    bad = (inverse(100) * (100 - prob)) % base;
    cout << solve(x, y, 1, 1).first << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}