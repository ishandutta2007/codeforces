#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
const int S = 26;

int pre[S][N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    for (int i = 1; i <= n; ++i) {
        char c = s[i - 1];
        pre[ c - 'a' ][i]++;
    }
    for (int i = 0; i < S; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] += pre[i][j - 1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        if (l == r) {
            cout << "Yes" << '\n';
        }
        else {
            string ans = "Yes";
            int tot = 0;
            int cnt = 0;
            for (int i = 0; i < 26; ++i) {
                int sz = pre[i][r] - pre[i][l - 1];
                if (sz == r - l + 1) {
                    ans = "No";
                }
                if (sz != 0) {
                    ++tot;
                    if (sz == 1) {
                        ++cnt;
                    }
                }
            }
            if (tot == 2 && s[l - 1] == s[r - 1]) {
                ans = "No";
            }
            cout << ans << '\n';
        }
    }
}