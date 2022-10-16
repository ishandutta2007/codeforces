#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int64_t x, n;
void solve() {
    cin >> x >> n;
    // -1 + 2 + 3 -4
    for (int64_t i = n - n % 4 + 1; i <= n; i++) {
        if (x % 2)
            x += i;
        else
            x -= i;
    }
    cout << x << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}