#include <bits/stdc++.h>
using namespace std;
int n, k;
int h[200001];
int low[200001];
int high[200001];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    low[1] = high[1] = h[1];
    for (int i = 1; i < n; i++) {
        if (low[i] > high[i]) {
            cout << "NO\n";
            return;
        }
        low[i + 1] = max(low[i] - k + 1, h[i + 1]);
        high[i + 1] = min(high[i] + k - 1, h[i + 1] + k - 1);
    }
    if ((low[n] > h[n]) || (high[n] < h[n])) cout << "NO\n";
    else cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}