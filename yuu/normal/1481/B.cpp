#include <bits/stdc++.h>
using namespace std;
int n, k;
int h[101];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int ans = -1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            if (h[j] < h[j + 1]) {
                h[j]++;
                ans = j;
                goto next_i;
            }
        }
        ans = -1;
        break;
    next_i:;
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