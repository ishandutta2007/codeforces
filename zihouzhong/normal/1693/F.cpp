#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int cnt = count(s.begin(), s.end(), '1');
        if (cnt > n - cnt) {
            reverse(s.begin(), s.end()), cnt = n - cnt;
            for (char &c : s) c ^= 1;
        }
        int ans = 0, len = 0;
        while (len < n && s[len] == '0') len++;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + (s[i] == '0' ? 1 : -1);
        }
        vector<int> lst(2 * n + 1, -1);
        for (int i = 0; i <= n; i++) {
            lst[a[i] + n] = i;
        }
        while (len != n - cnt) {
            ans++;
            if (len >= n - 2 * cnt) len = n - cnt;
            else len += (lst[len + n] - len) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}