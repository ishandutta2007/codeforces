#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int T, n, a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i], b[a[i]] = i;
        }
        int l = b[0], r = b[0], ans = 1;
        for (int i = 1, p = 0; i < n; i++) {
            if (b[i] < l) p += l - b[i] - 1, l = b[i];
            else if (b[i] > r) p += b[i] - r - 1, r = b[i];
            else ans = 1LL * ans * p-- % P;
        }
        cout << ans << "\n";
    }
    return 0;
}