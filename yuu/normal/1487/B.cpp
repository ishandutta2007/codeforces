#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
    cin >> n >> k;
    int skip = 0;
    if (n % 2) {
        skip = (k - 1) / (n / 2);
    }
    cout << (k - 1 + skip) % n + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}