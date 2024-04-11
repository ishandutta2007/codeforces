#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
int b[100001];
int c[100001];
int ans[100001];
vector<int> pos[100001];
vector<int> done;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) pos[i].clear();
    for (int i = 1; i <= n; i++) {
        pos[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        partition(pos[i].begin(), pos[i].end(), [](const int &idx) { return a[idx] == b[idx]; });
    }
    done.clear();
    for (int i = m; i >= 1; i--) {
        if (pos[c[i]].empty()) {
            if (done.empty()) {
                cout << "No\n";
                return;
            } else {
                ans[i] = done.back();
            }
        } else {
            ans[i] = pos[c[i]].back();
            done.push_back(pos[c[i]].back());
            pos[c[i]].pop_back();
        }
    }
    for (int i = 1; i <= m; i++) {
        a[ans[i]] = c[i];
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i]) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
    for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}