#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> ans;
deque<int> avail;
void solve() {
    cin >> n >> k;
    avail.clear();
    ans.clear();
    for (int i = 1; i <= n; i++) avail.push_back(i);
    int cnt = k;
    while (!avail.empty()) {
        ans.push_back(avail.front());
        avail.pop_front();
        if (avail.empty()) break;
        if (k > 0) {
            k--;
            ans.push_back(avail.back());
            avail.pop_back();
        }
    }
    assert(ans.size() == n);
    for (int i = 1; i + 1 < n; i++) {
        if ((ans[i] > ans[i - 1]) && (ans[i] > ans[i + 1])) cnt--;
    }
    if (cnt) {
        cout << "-1\n";
        return;
    }
    for (auto&& x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}