#define pd(x) cerr << __LINE__ << ": " << #x << ' ' << (x) << '\n'
#include <bits/stdc++.h>
using namespace std;
int a[3];
void solve() {
    cin >> a[0] >> a[1] >> a[2];
    int sum = a[0] + a[1] + a[2];
    cout << (bool(sum % 3)) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}