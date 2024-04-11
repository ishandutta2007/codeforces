#include <bits/stdc++.h>
using namespace std;
class zero_range_t {
public:
    int l, r;
    zero_range_t(int l, int r) : l(l), r(r) {}

    inline const int length() const { return r - l + 1; }

    bool operator<(const zero_range_t& other) const {
        if (length() != other.length()) return length() < other.length();
        return l > other.l;
    }
};
int a[200001];
void solve() {
    priority_queue<zero_range_t> q;
    int n;
    cin >> n;
    q.emplace(1, n);
    int step = 0;
    while (!q.empty()) {
        auto [l, r] = q.top();
        q.pop();
        int m = (l + r) / 2;
        a[m] = ++step;
        if (l < m) q.emplace(l, m - 1);
        if (m < r) q.emplace(m + 1, r);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}