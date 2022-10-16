#include <bits/stdc++.h>
using namespace std;
int n;
int64_t k;
int64_t a[200001];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) a[i] += a[i - 1];
    int64_t ans = max(0LL, a[n] - k);
    for (int i = n; i >= 2; i--) {
        int64_t left = k - (a[i - 1] - a[1]);  // sum cannot exceed this value
        int64_t count = n - i + 2;
        int64_t req = left / count;
        while (req * count <= left) req++;
        while (req * count > left) req--;
        ans = min(ans, max(0LL, max(0LL, a[1] - req) + (n - i + 1)));
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