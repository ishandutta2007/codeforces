#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    int64_t k = 2;
    while ((n * 2) % (k * 2) == 0) k *= 2;

    if ((k <= 1.5e9) && (k * (k + 1) <= n * 2)) {
        assert((n - k * (k + 1) / 2) % k == 0);
        cout << k << '\n';
        return;
    }

    k = n * 2 / k;
    assert(k % 2);
    if (k > 2) {
        if ((k <= 1.5e9) && (k * (k + 1) <= n * 2)) {
            assert((n - k * (k + 1) / 2) % k == 0);
            cout << k << '\n';
            return;
        }
    }
    cout << "-1\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}