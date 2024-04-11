#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        int l = INT_MIN, r = INT_MAX, ans = 0;
        while (n--) {
            int v;
            cin >> v;
            l = max(l, v - x), r = min(r, v + x);
            if (l > r) ans++, l = v - x, r = v + x;
        }
        cout << ans << "\n";
    }
    return 0;
}