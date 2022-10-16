#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
    } else if (n == 2) {
        cout << "1\n";
    } else if ((n > 3) && (n % 2)) {
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