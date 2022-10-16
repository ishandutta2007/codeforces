#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> full, empt;
int ans[5001];
void solve() {
    cin >> n;
    empt.push_back(0);
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a)
            full.push_back(i);
        else
            empt.push_back(i);
    }
    assert(empt.size() >= full.size() + 1);
    if (full.empty()) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < empt.size(); i++) ans[i] = 1e9;
    ans[0] = 0;
    for (auto&& x : full) {
        int mi = ans[0];
        for (int i = 1; i < empt.size(); i++) {
            int temp = ans[i];
            ans[i] = mi + abs(empt[i] - x);
            if (ans[i] > 1e9) ans[i] = 1e9;
            mi = min(mi, temp);
        }
        ans[0] = 1e9;
    }
    cout << *min_element(ans + 1, ans + empt.size());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}