#include <bits/stdc++.h>
using namespace std;
int min_path[1001];
void prepare() {
    for (int i = 1; i <= 1000; i++) min_path[i] = i;
    min_path[1] = 0;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= i; j++) {
            if (i + i / j <= 1000) min_path[i + i / j] = min(min_path[i + i / j], min_path[i] + 1);
        }
}

int n, k;
int f[12001];
int b[1001];
int c[1001];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = min_path[b[i]];
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (accumulate(b + 1, b + n + 1, 0) <= k) {
        cout << accumulate(c + 1, c + n + 1, 0) << '\n';
        return;
    }
    int add = 0;
    for (int i = 0; i <= k; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= b[i]; j--) {
            f[j] = max(f[j], f[j - b[i]] + c[i]);
        }
    }
    cout << *max_element(f, f + k + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    // cerr << min_path[1000] << '\n';  // 12
    int t = 1;
    cin >> t;
    while (t--) solve();
}