#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
int get(int c_1, int c_2) {
    if ((a[1] == 1) && (c_1 == 0)) return 1e9;
    int c_3 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            if (c_1 == 0) return 1e9;
        } else if (a[i] == 2) {
            if (c_2 == 0) return 1e9;
        } else if (a[i] % 3 == 0) {
            if (c_1 && c_2)
                c_3 = max(c_3, (a[i] - 3) / 3);
            else
                c_3 = max(c_3, a[i] / 3);
        } else if ((a[i] % 3) == 1) {
            if (c_2 == 2)
                c_3 = max(c_3, (a[i] - 4) / 3);
            else if (c_1 == 0)
                return 1e9;
            else
                c_3 = max(c_3, a[i] / 3);
        } else if ((a[i] % 3) == 2) {
            if (c_2 == 0)
                return 1e9;
            else if ((c_2 == 2) && (c_1 == 1))
                c_3 = max(c_3, (a[i] - 5) / 3);
            else
                c_3 = max(c_3, (a[i] - 2) / 3);
        }
    }
    return c_1 + c_2 + c_3;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 1e9;
    ans = min(ans, get(0, 0));
    ans = min(ans, get(0, 1));
    ans = min(ans, get(0, 2));
    ans = min(ans, get(1, 0));
    ans = min(ans, get(1, 1));
    ans = min(ans, get(1, 2));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}