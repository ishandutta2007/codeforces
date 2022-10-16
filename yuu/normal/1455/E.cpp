#include <bits/stdc++.h>
using namespace std;
class Point {
public:
    int x, y;
} p[4];
int position[] = {0, 1, 2, 3};
int64_t ans;
vector<int> x, y;
void check(int64_t x_0, int64_t y_0, int64_t x_1, int64_t y_1) {
    do {
        int64_t cost = 0;
        for (int i = 0; i < 4; i++) {
            if (i & 1) cost += abs(x_1 - p[position[i]].x);
            else cost += abs(x_0 - p[position[i]].x);
            if (i & 2) cost += abs(y_1 - p[position[i]].y);
            else cost += abs(y_0 - p[position[i]].y);
        }
        ans = min(ans, cost);
    } while (next_permutation(position, position + 4));
}
void optimise_cost() {
    int sz = 0;
    if (x.size() == 2) sz = abs(x[1] - x[0]);
    else sz = abs(y[1] - y[0]);
    if (x.size() == 2) {
        check(x[0], y[0], x[1], y[0] + sz);
        check(x[0], y[0], x[1], y[0] - sz);
    } else {
        check(x[0], y[0], x[0] + sz, y[1]);
        check(x[0], y[0], x[0] - sz, y[1]);
    }
}

void backtrack() {
    if (x.empty()) {
        x.push_back(0);
        for (int i = 0; i < 4; i++) {
            x.back() = p[i].x;
            backtrack();
        }
        x.pop_back();
    } else if (y.empty()) {
        y.push_back(0);
        for (int i = 0; i < 4; i++) {
            y.back() = p[i].y;
            backtrack();
        }
        y.pop_back();
    } else if (x.size() + y.size() == 2) {
        x.push_back(0);
        for (int i = 0; i < 4; i++) {
            x.back() = p[i].x;
            backtrack();
        }
        x.pop_back();
        y.push_back(0);
        for (int i = 0; i < 4; i++) {
            y.back() = p[i].y;
            backtrack();
        }
        y.pop_back();
    } else {
        optimise_cost();
    }
}
void solve() {
    for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
    ans = 1e18;
    backtrack();
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ;
    int t = 1;
    cin >> t;
    while (t--) solve();
}