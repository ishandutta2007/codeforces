#include <bits/stdc++.h>
using namespace std;
int64_t n, m;
bool done[1000001];
bool check[20000001];
int64_t g[21];
void prepare() {
    int ans = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= m; j++)
            if (!check[i * j]) {
                check[i * j] = 1;
                ans++;
            }
        g[i] = ans;
    }
}

void solve() {
    cin >> n >> m;
    prepare();
    int64_t ans = 1;
    for (int64_t i = 2; i <= n; i++)
        if (!done[i]) {
            done[i] = 1;
            int cnt = 1;
            int64_t j = i;
            while (j * i <= n) {
                j *= i;
                done[j] = 1;
                cnt++;
            }
            ans += g[cnt];
        }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}