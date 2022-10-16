#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = min_element(a + 1, a + n + 1) - a;
    cout << n - 1 << '\n';
    for (int j = i - 1, add = 1; j >= 1; j--, add = 1 - add) {
        cout << i << ' ' << j << ' ' << a[i] << ' ' << a[i] + add << '\n';
    }
    for (int j = i + 1, add = 1; j <= n; j++, add = 1 - add) {
        cout << i << ' ' << j << ' ' << a[i] << ' ' << a[i] + add << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}