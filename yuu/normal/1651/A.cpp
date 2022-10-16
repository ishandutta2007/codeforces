#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    cout << (1 << n) - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}