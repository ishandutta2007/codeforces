#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int mul = 1;
    while ((n % 2 == 0) && (n > 6)) {
        n /= 2;
        mul *= 2;
    }
    cout << mul << ' ' << (n - 3) * mul << ' ' << mul << ' ' << mul << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}