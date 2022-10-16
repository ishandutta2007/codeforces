#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << min_element(a + 1, a + n + 1) - a << ' ';
    cout << max_element(a + 1, a + n + 1) - a << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}