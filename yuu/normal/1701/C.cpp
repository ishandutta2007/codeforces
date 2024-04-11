#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[200001];
bool check(int lim) {
    int64_t rem = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > lim) {
            rem += cnt[i] - lim;
        } else {
            rem -= (lim - cnt[i]) / 2;
        }
    }
    return rem <= 0;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1, a; i <= m; i++) {
        cin >> a;
        cnt[a]++;
    }
    int low = 1, high = m * 2, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}