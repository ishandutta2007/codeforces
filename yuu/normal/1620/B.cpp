#include <bits/stdc++.h>
using namespace std;
int64_t w, h;
int k;
void solve() {
    cin >> w >> h;
    int64_t ans = 0;
    for (int i = 1; i <= 2; i++) {
        cin >> k;
        int first = -1;
        int last;
        cin >> first;
        for (int j = 2; j <= k; j++) cin >> last;
        ans = max(ans, h * (last - first));
    }
    for (int i = 1; i <= 2; i++) {
        cin >> k;
        int first = -1;
        int last;
        cin >> first;
        for (int j = 2; j <= k; j++) cin >> last;
        ans = max(ans, w * (last - first));
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