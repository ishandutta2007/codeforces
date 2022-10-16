#include <bits/stdc++.h>
using namespace std;
int n;
int a[51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum < n)
        cout << "1\n";
    else if (sum == n)
        cout << "0\n";
    else
        cout << sum - n << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}