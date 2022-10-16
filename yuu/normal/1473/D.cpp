#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[200001];
struct {
    int sum, low, high;
    int future_top, future_bot;
} prefix[200001];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        prefix[i].low = prefix[i - 1].low;
        prefix[i].high = prefix[i - 1].high;
        if (c[i] == '+') prefix[i].sum = prefix[i - 1].sum + 1;
        else prefix[i].sum = prefix[i - 1].sum - 1;
        if (prefix[i].sum < prefix[i].low) prefix[i].low = prefix[i].sum;
        if (prefix[i].sum > prefix[i].high) prefix[i].high = prefix[i].sum;
    }
    prefix[n].future_top = prefix[n].future_bot = prefix[n].sum;
    for (int i = n - 1; i >= 1; i--) {
        prefix[i].future_top = max(prefix[i + 1].future_top, prefix[i + 1].sum);
        prefix[i].future_bot = min(prefix[i + 1].future_bot, prefix[i + 1].sum);
    }
    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        l--;
        int low = min(prefix[l].low, prefix[l].sum + prefix[r].future_bot - prefix[r].sum);
        int high = max(prefix[l].high, prefix[l].sum + prefix[r].future_top - prefix[r].sum);
        cout << high - low + 1 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}