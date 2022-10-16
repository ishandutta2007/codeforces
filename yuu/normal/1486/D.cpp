#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200001];
int b[200001];
bool check(int val) {
    for (int i = 1; i <= n; i++) b[i] = (a[i] >= val);
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    // i -> j => (b[j] - b[i - 1]) * 2 > (j - i + 1)
    // b[j] * 2 - j > b[i-1] * 2 - (i - 1)
    // b[j] * 2 - j > b[i] * 2 - i
    // j - i >= k
    int low = 1e9;
    for (int j = k; j <= n; j++) {
        low = min(low, b[j - k] * 2 - (j - k));
        if (b[j] * 2 - j > low) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int low = 1, high = n, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}