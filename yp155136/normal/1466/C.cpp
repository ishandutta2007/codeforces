#include <bits/stdc++.h>
using namespace std;

string s;

char find_diff(int l, int r) {
    set<int> st;
    for (int i = l; i <= r; ++i) {
        if (0 <= i && i < (int)s.size()) {
            st.insert(s[i]);
        }
    }
    for (int i = 'a'; ; ++i) {
        if (st.find(i) == st.end()) return i;
    }
}

vector<int> pos[26];

int dp[200006][2];

void solve() {
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < 26; ++i) {
        pos[i].clear();
        pos[i].push_back(-3);
    }
    for (int i = 0; i < n; ++i) {
        pos[ s[i] - 'a' ].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        dp[0][0] = 0; // i not change
        dp[0][1] = 1; // i change
        for (int j = 1; j < pos[i].size(); ++j) {
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][1]) + 1;
            dp[j][0] = 123456789;
            for (int k = j - 1; k >= j - 5; --k) {
                if (k < 0) break;
                if (pos[i][j] - pos[i][k] > 2) {
                    dp[j][0] = min({dp[j][0], min(dp[k][0], dp[k][1]) + (j - k - 1)});
                }
            }
            // cerr << "j = " << j << " , dp = " << dp[0]
        }
        ans += min(dp[pos[i].size() - 1][0], dp[pos[i].size() - 1][1]);
        // cerr << "i = " << i << " , ans = " << ans << endl;
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}