// sleeping until 25 minutes into the contest be like
#include <bits/stdc++.h>
using namespace std;
unique_ptr<int[]> a[500001];
unique_ptr<int[]> rmx[500001];
unique_ptr<int[]> rmi[500001];
int lmx[500001];
int lmi[500001];
int ord[500001];
int rcmx[500001];
char ans[500001];
int n, m;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = make_unique<int[]>(m + 1);
        rmx[i] = make_unique<int[]>(m + 1);
        rmi[i] = make_unique<int[]>(m + 1);
        for (int j = 1; j <= m; j++) cin >> a[i][j];
        rmx[i][m] = rmi[i][m] = a[i][m];
        for (int j = m - 1; j >= 1; j--) rmx[i][j] = max(a[i][j], rmx[i][j + 1]);
        for (int j = m - 1; j >= 1; j--) rmi[i][j] = min(a[i][j], rmi[i][j + 1]);
        lmx[i] = lmi[i] = a[i][1];
        ord[i] = i;
    }

    for (int split = 1; split < m; split++) {
        for (int i = 1; i <= n; i++) lmx[i] = max(lmx[i], a[i][split]);
        for (int i = 1; i <= n; i++) lmi[i] = min(lmi[i], a[i][split]);
        sort(ord + 1, ord + n + 1, [](const int& x, const int& y) { return lmi[x] < lmi[y]; });

        rcmx[n] = rmx[ord[n]][split + 1];
        for (int i = n - 1; i >= 1; i--) rcmx[i] = max(rcmx[i + 1], rmx[ord[i]][split + 1]);
        int lcmx = 0;
        int rcmi = 1e9;
        for (int i = 1; i < n; i++) {
            lcmx = max(lcmx, lmx[ord[i]]);
            rcmi = min(rcmi, rmi[ord[i]][split + 1]);
            if ((lcmx < lmi[ord[i + 1]]) && (rcmi > rcmx[i + 1])) {
                cout << "YES\n";
                for (int j = 1; j <= n; j++) ans[ord[j]] = "BR"[j > i];
                for (int j = 1; j <= n; j++) cout << ans[j];
                cout << ' ' << split << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}