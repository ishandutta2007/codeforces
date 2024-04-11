#include <bits/stdc++.h>
using namespace std;
int n;
int a[51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n * 2; i++) cin >> a[i];
    sort(a + 1, a + n * 2 + 1);
    for (int i = 1; i <= n; i++) cout << a[i] << ' ' << a[i + n] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}