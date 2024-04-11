#define pd(x) cerr << __LINE__ << ": " << #x << ' ' << (x) << '\n'
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
deque<int> pos[2];
vector<int> ans;
void solve() {
    cin >> n >> s;
    pos[0].clear();
    pos[1].clear();
    for (int i = 0; i < n; i++) pos[s[i] - '0'].push_back(i + 1);
    ans.clear();
    while ((!pos[0].empty()) && (!pos[1].empty())) {
        if (pos[0].back() < pos[1].front()) break;
        ans.push_back(pos[0].back());
        ans.push_back(pos[1].front());
        pos[0].pop_back();
        pos[1].pop_front();
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << "0\n";
        return;
    }
    cout << 1 << '\n';
    cout << ans.size();
    for (auto& x : ans) cout << ' ' << x;
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}