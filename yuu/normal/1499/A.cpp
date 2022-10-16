#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b, int t) { return t <= (a + b) / 2; }
void solve() {
    int n, k1, k2;
    int w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if (check(k1, k2, w) && (check(n - k1, n - k2, b)))
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}