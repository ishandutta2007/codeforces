#include <bits/stdc++.h>
using namespace std;

// total score % 2 == 0
int n;
int ans[100][100];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) ans[i][j] = 0;
    for (int shift = 1; shift * 2 < n; shift++) {
        int g = gcd(shift, n);
        int cycle_size = n / g;
        for (int i = 0; i < g; i++) {
            int u = i;
            for (int j = 0; j < cycle_size; j++) {
                int v = (u + shift) % n;
                ans[u][v] = 1;
                ans[v][u] = -1;
                u = v;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) cout << ans[i][j] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}