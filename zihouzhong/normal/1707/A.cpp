#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        auto chk = [&](int lim) {
            int cur = q, cnt = 0;
            for (int i = 0; i < n && cur; i++) {
                if (cur < a[i]) {
                    if (cnt + n - i - 1 < lim) cnt++, cur--;
                } else {
                    cnt++;
                }
            }
            return cnt >= lim;
        };
        int l = 1, r = n, lim;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? l = (lim = mid) + 1 : r = mid - 1;
        }
        string res(n, '0');
        int cur = q, cnt = 0;
        for (int i = 0; i < n && cur; i++) {
            if (cur < a[i]) {
                if (cnt + n - i - 1 < lim) res[i] = '1', cnt++, cur--;
            } else {
                res[i] = '1', cnt++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}