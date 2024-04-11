#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    if (n <= 4) {
        cout << "0\n";
        return;
    }
    n--;
    // b <= n
    int64_t lim = n * 2 + 1;
    int64_t max_a = sqrt(lim);
    while (max_a * max_a <= lim) max_a++;
    while (max_a * max_a > lim) max_a--;
    cout << (max_a - 1) / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}