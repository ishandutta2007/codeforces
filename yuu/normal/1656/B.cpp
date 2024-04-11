#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200001];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while ((j <= n) && (a[j] - a[i] < k)) j++;
        if (j > n) break;
        if (a[j] - a[i] == k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}