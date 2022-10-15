#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, K, a[maxn];
long long s[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> K;
        for (int i = 1; i <= n; i++) {
            cin >> a[i], s[i] = s[i - 1] + a[i];
        }
        long long ans = 0;
        if (n >= K) {
            for (int i = 1; i + K - 1 <= n; i++) {
                ans = max(ans, s[i + K - 1] - s[i - 1] + 1LL * K * (K - 1) / 2);
            }
        } else {
            for (int i = 1; i <= n; i++) {
                ans += a[i] + K - i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}