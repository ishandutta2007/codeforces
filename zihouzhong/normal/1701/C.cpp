#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &x : a) cin >> x, x--;
        auto chk = [&](int lim) {
            vector<int> cur(n);
            long long cnt = 0;
            for (int i = 0; i < m; i++) {
                if (cur[a[i]] < lim) cur[a[i]]++, cnt++;
            }
            for (int i = 0; i < n; i++) {
                cnt += (lim - cur[i]) / 2;
            }
            return cnt >= m;
        };
        int l = 0, r = 2 * m, ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}