#include <bits/stdc++.h>
using namespace std;
int n;
int64_t c[100001];
int64_t a[100091];
int64_t b[100091];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int64_t ans = 0;
    int64_t lead = 0;
    for (int i = 2; i <= n; i++) {
        if (i == 2) {
            lead = abs(a[i] - b[i]) + 2;
        } else if (a[i] == b[i]) {
            lead = 2;
        } else if (a[i] < b[i]) {
            lead = max(lead + (a[i] - 1) + (c[i - 1] - b[i]), (b[i] - a[i])) + 2;
        } else {
            lead = max(lead + (c[i - 1] - a[i]) + (b[i] - 1), (a[i] - b[i])) + 2;
        }
        ans = max(ans, lead + c[i] - 1);
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