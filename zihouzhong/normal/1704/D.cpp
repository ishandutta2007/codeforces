#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<__int128>> c(n, vector<__int128>(m));
        int k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll x;
                cin >> x, c[i][j] = x;
            }
            partial_sum(c[i].begin(), c[i].end(), c[i].begin());
            partial_sum(c[i].begin(), c[i].end(), c[i].begin());
        }
        __int128 need = 0;
        for (int i = 0; i < m; i++) {
            __int128 mx = numeric_limits<__int128>::min();
            for (int j = 0; j < n; j++) {
                mx = max(mx, c[j][i]);
            }
            for (int j = 0; j < n; j++) {
                if (c[j][i] < mx) k = j;
            }
        }
        for (int i = 0; i < n; i++) if (i != k) {
            need += c[i].back(); break;
        }
        need -= c[k].back();
        cout << k + 1 << " " << (long long)need << "\n";
    }
    return 0;
}