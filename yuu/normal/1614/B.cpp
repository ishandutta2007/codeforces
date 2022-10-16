#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
vector<int> order;
int pos[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    order.clear();
    for (int i = 1; i <= n; i++) order.push_back(i);
    sort(order.begin(), order.end(), [](const int &x, const int &y) { return a[x] > a[y]; });
    int val = 1;
    for (auto &&i : order) {
        pos[i] = val;
        if (val > 0)
            val = -val;
        else
            val = -val + 1;
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) ans += static_cast<int64_t>(abs(pos[i])) * a[i];
    cout << ans * 2 << '\n';
    for (int i = 0; i <= n; i++) cout << pos[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}