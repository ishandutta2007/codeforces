#include <bits/stdc++.h>
using namespace std;
int n;
int x[1001];
int y[1001];

int64_t solve(int* a) {
    sort(a + 1, a + n + 1);
    int low = (n + 1) / 2;
    int high = (n + 2) / 2;
    return a[high] - a[low] + 1;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    cout << solve(x) * solve(y) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}