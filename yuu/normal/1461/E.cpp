#include <bits/stdc++.h>
using namespace std;
int64_t k, l, r, t, x, y;
void no() {
    cout << "No\n";
    exit(0);
}
void yes() {
    cout << "Yes\n";
    exit(0);
}
bitset<1000001> done;
void solve() {
    cin >> k >> l >> r >> t >> x >> y;
    k -= l;
    r -= l;

    if (y < x) {
        if (k + y <= r) k += y;
        if (k - x < 0) no();
        k -= x;
        t--;
        int64_t day_lasted = k / (x - y);
        while (k - day_lasted * (x - y) >= 0) day_lasted++;
        while (k - day_lasted * (x - y) < 0) day_lasted--;
        if (day_lasted >= t) yes();
        else no();
    } else if (x == y) {
        if (k + y <= r) k += y;
        if (k - x < 0) no();
        else yes();
    }
    // y > x
    if (x - 1 + y <= r) yes();
    if (y > r) {
        int64_t day_lasted = k / x;
        if (day_lasted >= t) yes();
        else no();
    }
    // y <= r
    int64_t lim = r - y;
    assert(lim < x);
    while (k + y <= r) k += y;
    while (true) {
        int64_t day_lasted = k / x;
        if (day_lasted >= t) yes();
        k -= day_lasted * x;
        t -= day_lasted;
        if (k > lim) no();
        if (done[k]) yes();
        done[k] = 1;
        k += y;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}