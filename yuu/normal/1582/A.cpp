#include <bits/stdc++.h>
#define pdebug(x) cerr << __LINE__ << ": " << #x << " = " << x << '\n'
using namespace std;
int64_t a, b, c;
void solve() {
    cin >> a >> b >> c;
    int64_t sum = a + b * 2 + c * 3;
    cout << sum % 2 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}