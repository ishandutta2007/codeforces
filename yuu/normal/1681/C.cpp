#include <bits/stdc++.h>
using namespace std;
int n;
struct {
    int id;
    int a, b;
} p[101];
bool done[101];
vector<pair<int, int>> ans;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].a;
    for (int i = 1; i <= n; i++) cin >> p[i].b;
    for (int i = 1; i <= n; i++) p[i].id = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if ((p[i].a > p[j].a) && (p[i].b < p[j].b)) {
                cout << "-1\n";
                return;
            }
        }
    ans.clear();
    sort(p + 1, p + n + 1, [](const auto& A, const auto& B) { return (A.a < B.a) || ((A.a == B.a) && (A.b < B.b)); });
    for (int i = 1; i <= n; i++) done[i] = 0;
    vector<int> cycle;
    for (int i = 1; i <= n; i++)
        if (!done[i]) {
            cycle.clear();
            cycle.push_back(i);
            done[cycle.back()] = 1;
            while (!done[p[cycle.back()].id]) {
                cycle.push_back(p[cycle.back()].id);
                done[cycle.back()] = 1;
            }
            for (int j = 1; j < cycle.size(); j++) ans.emplace_back(cycle[j - 1], cycle[j]);
        }
    cout << ans.size() << '\n';
    for (auto&& [x, y] : ans) cout << x << ' ' << y << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}