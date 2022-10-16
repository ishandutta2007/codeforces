#include <bits/stdc++.h>
using namespace std;
int n;
int a[51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (is_sorted(a + 1, a + n + 1)) {
        cout << "0\n";
        return;
    }
    if ((a[1] == 1) || (a[n] == n)) {
        cout << "1\n";
    } else if ((a[1] == n) && (a[n] == 1)) {
        cout << "3\n";
    } else {
        cout << "2\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}