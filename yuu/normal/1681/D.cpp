#include <bits/stdc++.h>
using namespace std;
int n;
uint64_t x, req = 1;
class State {
public:
    uint64_t num;
    int avail;

    State(uint64_t x) : num(x), avail(0) {
        while (x) {
            avail |= (1 << (x % 10));
            x /= 10;
        }
    }

    int min_cost() {
        uint64_t best = num;
        int res = 0;
        while (best < req) {
            best *= 9;
            res++;
        }
        return res;
    }
};
int ans = 1e9;

void backtrack(int move_count, State current) {
    if (move_count >= ans) return;
    if (current.num >= req) {
        ans = move_count;
        return;
    }
    int best_hope = move_count + current.min_cost();
    for (int i = 9; i >= 2; i--)
        if ((current.avail >> i) & 1) {
            backtrack(move_count + 1, State(current.num * i));
            if (best_hope >= ans) return;
        }
}

void solve() {
    cin >> n >> x;
    for (int i = 1; i < n; i++) req *= 10;
    backtrack(0, State(x));
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}