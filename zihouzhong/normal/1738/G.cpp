#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector a(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            a[i][j] = str[j] - '0';
        }
    }
    vector res(n, string(n, '1'));
    vector len(n - k + 1, vector<int>(n - k + 1));
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            if (i) len[i][j] = max(len[i][j], len[i - 1][j]);
            if (j) len[i][j] = max(len[i][j], len[i][j - 1]);
            while (max(i, j) + len[i][j] < n && !a[i + len[i][j]][j +
                len[i][j]]) len[i][j]++;
            if (max(i, j) + len[i][j] == n) { cout << "NO\n"; return; }
            res[i + len[i][j]][j + len[i][j]] = '0';
        }
    }
    cout << "YES\n";
    for (auto &x : res) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}