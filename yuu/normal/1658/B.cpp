#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int base = 998244353;
int64_t f[1001];
void solve() {
    cin >> n;
    if (n % 2) {
        cout << "0\n";
        return;
    }
    n /= 2;
    cout << (f[n] * f[n]) % base << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i <= 1000; i++) (f[i] = f[i - 1] * i) %= base;
    int t = 1;
    cin >> t;
    while (t--) solve();
}