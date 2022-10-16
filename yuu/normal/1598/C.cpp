#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[200001];
int64_t sum;
map<int64_t, int> cnt;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    // sum / n == new_sum / (n - 2)
    // sum * (n - 2) == new_sum * n
    int64_t new_sum = sum;
    int64_t x = n, y = n - 2;
    int64_t d = gcd(x, y);
    x /= d;
    y /= d;
    if (new_sum % x) {
        cout << "0\n";
        return;
    }
    new_sum /= x;
    new_sum *= y;
    cnt.clear();
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt.count(sum - a[i] - new_sum)) ans += cnt[sum - a[i] - new_sum];
        cnt[a[i]]++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}