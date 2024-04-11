#include <bits/stdc++.h>
using namespace std;
int n, m;
deque<tuple<int, int, int>> r;
int a[500001];
int b[500001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    r.clear();
    for (int i = 1; i <= n; i++) {
        // i / a[i] = b[i]
        // b[i] * a[i] + r = i
        // b[i] * a[i] = i - r
        // i >= i - r > i - a[i]
        // b[i] * a[i] <= i
        // b[i] * a[i] > i - a[i]
        // (b[i] + 1) * a[i] > i
        // (i / (b[i] + 1)) < a[i] <= i / b[i]
        int low = i / (b[i] + 1) + 1;
        int high = b[i] ? (i / b[i]) : n;
        assert(i / low == b[i]);
        assert(i / high == b[i]);
        assert((high == n) || (i / (high + 1) != b[i]));
        assert((low == 1) || (i / (low - 1) != b[i]));
        // cerr << i << ' ' << low << ' ' << high << '\n';
        r.emplace_back(low, high, i);
    }
    sort(r.begin(), r.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        while (!r.empty()) {
            auto&& [l, h, id] = r.front();
            if (l > i) break;
            q.emplace(h, id);
            r.pop_front();
        }
        assert(!q.empty());
        assert(i <= q.top().first);
        a[q.top().second] = i;
        q.pop();
    }
    for (int i = 1; i <= n; i++) assert(i / a[i] == b[i]);
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}