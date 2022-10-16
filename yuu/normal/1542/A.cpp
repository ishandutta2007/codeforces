#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    int odd = 0;
    for (int i = 1, a; i <= n * 2; i++) {
        cin >> a;
        odd += a % 2;
    }
    if (odd == n)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}