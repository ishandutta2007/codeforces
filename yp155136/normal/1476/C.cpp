#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100006;

ll c[N], a[N], b[N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        ll ans = 0, pre = (a[2] == b[2] ? 1 : abs(a[2] - b[2]) + 1);
        for (int i = 2; i <= n; ++i) {
            if (pre == 0) ans = max(ans, pre + c[i] + abs(a[i] - b[i]) + 1);
            else ans = max(ans, pre + c[i]);
            if (a[i + 1] == b[i + 1]) {
                pre = 1;
            }
            else {
                pre = max(abs(a[i + 1] - b[i + 1]) + 1, pre + (c[i] - abs(a[i + 1] - b[i + 1]) + 1));
            }
        }
        cout << ans << endl;
    }
}