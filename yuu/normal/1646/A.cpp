#include <bits/stdc++.h>
using namespace std;
int64_t n, s;
void solve() {
    cin >> n >> s;
    cout << s / (n * n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}