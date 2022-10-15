#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        int n = s.size(), cnt = count(s.begin(), s.end(), '1');
        if (!cnt) { cout << "-1\n"; continue; }
        vector<int> suf(n + 1);
        for (int i = n - 1; ~i; i--) {
            suf[i] = suf[i + 1] + s[i] - '0';
        }
        int need = 1;
        while (need < cnt) need *= 2;
        vector<array<int, 2>> ans;
        if (need <= 8) {
            need *= 2;
            vector<vector<bool>> f(n + 1, vector<bool>(need + 1));
            vector<vector<int>> pre(n + 1, vector<int>(need + 1));
            f[0][0] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= need; j++) if (f[i][j]) {
                    if (s[i] == '0') { f[i + 1][j] = 1, pre[i + 1][j] = i; continue; }
                    for (int k = i + 1, x = 0; k <= min(n, i + 4); k++) {
                        x = 2 * x + s[k - 1] - '0';
                        if (j + x <= need) f[k][j + x] = 1, pre[k][j + x] = i;
                    }
                }
            }
            int i = n, j = 1;
            while (!f[i][j]) j *= 2;
            while (i) {
                int _i = pre[i][j], x = 0;
                ans.push_back({_i, i - 1});
                for (int p = _i; p < i; p++) x = 2 * x + s[p] - '0';
                j -= x, i = _i;
            }
            reverse(ans.begin(), ans.end());
        } else {
            for (int i = 0, j; i < n; i = j + 1) {
                if (s[i] == '0') { ans.push_back({i, j = i}); continue; }
                int cur = 1;
                for (j = i + 1; j < n; j++) {
                    cur = cur * 2 + s[j] - '0';
                    if (suf[j + 1] + cur > need) { cur /= 2, j--; break; }
                }
                ans.push_back({i, min(j, n - 1)}), need -= cur;
            }
        }
        cout << ans.size() << "\n";
        for (auto &p : ans) {
            cout << p[0] + 1 << " " << p[1] + 1 << "\n";
        }
    }
    return 0;
}