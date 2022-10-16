#include <bits/stdc++.h>
using namespace std;
int n;
vector<int64_t> ans;
void solve() {
    cin >> n;
    if (n > ans.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans.push_back(1);
    while (ans.back() * 3 <= 1'000'000'000) {
        ans.push_back(ans.back() * 3);
    }
    int t = 1;
    cin >> t;
    while (t--) solve();
}