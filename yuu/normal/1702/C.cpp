#include <bits/stdc++.h>
using namespace std;
int n, k;
map<int, int> min_pos, max_pos;
void solve() {
    cin >> n >> k;
    min_pos.clear();
    max_pos.clear();
    for (int i = 1, u; i <= n; i++) {
        cin >> u;
        if (min_pos.count(u)) {
            min_pos[u] = min(min_pos[u], i);
            max_pos[u] = max(max_pos[u], i);
        } else {
            max_pos[u] = min_pos[u] = i;
        }
    }
    for (int i = 1, a, b; i <= k; i++) {
        cin >> a >> b;
        if (min_pos.count(a) && min_pos.count(b) && (min_pos[a] <= max_pos[b])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}