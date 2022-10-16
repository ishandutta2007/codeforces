#include <bits/stdc++.h>
using namespace std;
class Query {
  public:
    int t, x, y;
} q[500001];
int result[500001];
vector<int> ans;
int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= 500000; i++) result[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> q[i].t >> q[i].x;
        if (q[i].t == 2) cin >> q[i].y;
    }
    for (int i = n; i >= 1; i--) {
        if (q[i].t == 1)
            ans.push_back(result[q[i].x]);
        else
            result[q[i].x] = result[q[i].y];
    }
    reverse(ans.begin(), ans.end());
    for (auto&& x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}