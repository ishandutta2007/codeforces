#include <bits/stdc++.h>
using namespace std;
int n;
int64_t p;
int a[200001];
bool done[200001];
vector<int> order;
void solve() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    order.clear();
    for (int i = 1; i <= n; i++) order.push_back(i);
    for (int i = 1; i <= n; i++) done[i] = 0;
    sort(order.begin(), order.end(), [](const int &x, const int &y) { return a[x] < a[y]; });
    int cnt = n;
    int64_t ans = 0;
    for (auto &&i : order) {
        if (a[i] >= p) break;
        if (done[i]) continue;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] % a[i]) break;
            cnt--;
            ans += a[i];
            if (done[j]) break;
            done[j] = 1;
        }
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] % a[i]) break;
            cnt--;
            ans += a[i];
            if (done[j]) break;
            done[j] = 1;
        }
    }
    ans += p * (cnt - 1);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}