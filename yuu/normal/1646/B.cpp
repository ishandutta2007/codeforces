#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[200001];
int64_t f[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    f[n] = a[n];
    for (int i = n - 1; i >= 1; i--) f[i] = f[i + 1] + a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 2; i <= n; i++) {
        int j = n - i + 2;
        if (j < i) break;
        if (a[i] < f[j]) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}