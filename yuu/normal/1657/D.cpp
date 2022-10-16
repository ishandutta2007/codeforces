#include <bits/stdc++.h>
using namespace std;
int n, c;

int64_t best[1000001];

void solve() {
    cin >> n >> c;
    for (int i = 1, cost, damage, health; i <= n; i++) {
        cin >> cost >> damage >> health;
        best[cost] = max(best[cost], static_cast<int64_t>(damage) * health);
    }
    for (int i = 1; i <= c; i++) {
        int64_t sum = best[i];
        for (int j = i; j <= c; j += i) {
            best[j] = max(best[j], sum);
            sum += best[i];
        }
    }
    for (int i = 1; i <= c; i++) best[i] = max(best[i], best[i - 1]);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int64_t damage, health;
        cin >> damage >> health;
        int64_t power = damage * health;
        int low = 1, high = c, ans = -1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (best[mid] > power) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " \n"[i == m];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}