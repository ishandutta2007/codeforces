#include <bits/stdc++.h>
using namespace std;
int n;
char a[101][101];
bool done[101][101];

void rotate(int &u, int &v) {
    int t = n - u + 1;
    u = v;
    v = t;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            done[i][j] = 0;
            cin >> a[i][j];
            a[i][j] -= '0';
        }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (done[i][j]) continue;
            int sum = 0;
            int u = i, v = j;
            for (int cnt = 0; cnt < 4; cnt++) {
                done[u][v] = 1;
                sum += a[u][v];
                rotate(u, v);
            }
            ans += min(sum, 4 - sum);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}