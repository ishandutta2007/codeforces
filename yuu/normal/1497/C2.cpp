#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
    cin >> n >> k;
    while (k > 3) {
        cout << "1 ";
        k--;
        n--;
    }
    int mul = 1;
    while ((n > 4) && (n % 2 == 0)) {
        n /= 2;
        mul *= 2;
    }
    if (n % 2) {
        cout << mul << ' ' << mul * (n / 2) << ' ' << mul * (n / 2) << '\n';
    } else {
        cout << mul * 2 << ' ' << mul << ' ' << mul << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}