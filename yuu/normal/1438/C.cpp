#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, a; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a;
            if ((a + i + j) % 2) a++;
            cout << a << " \n"[j == m];
        }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}