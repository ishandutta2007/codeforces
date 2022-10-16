#include <bits/stdc++.h>
using namespace std;
int x, y;
void solve() {
    cin >> x >> y;
    if ((x + y) % 2) {
        cout << "-1 -1\n";
        return;
    }
    cout << x / 2 << ' ' << (x + y) / 2 - x / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}