#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    int ans = 1;
    int add = 1;
    int bad = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (ans == -1) continue;
        if (a == 0) {
            if (bad)
                ans = -1;
            else
                bad = 1;
            add = 1;
        } else {
            ans += add;
            add = 5;
            bad = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}