#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int last = -1;
        int ans = 0, now = 0;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if (last == x) ++now;
            else now = 1;
            ans = max(ans, now);
            last = x;
        }
        cout << ans << endl;
    }
}