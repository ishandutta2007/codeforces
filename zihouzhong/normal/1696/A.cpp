#include <bits/stdc++.h>
using namespace std;

int T, n, z, a[2010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> z;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i] | z);
        }
        cout << ans << "\n";
    }
    return 0;
}