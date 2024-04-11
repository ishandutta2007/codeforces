#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int64_t sum = accumulate(a + 1, a + n + 1, 0LL);
    int64_t low = (sum - 1) / (n - 1) + 1;
    while (low * (n - 1) >= sum) low--;
    while (low * (n - 1) < sum) low++;
    if (low < a[n]) low = a[n];
    cout << low * (n - 1) - sum << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}