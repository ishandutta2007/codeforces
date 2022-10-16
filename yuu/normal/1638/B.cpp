#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[2];
void solve() {
    cin >> n;
    v[0].clear();
    v[1].clear();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        v[x % 2].push_back(x);
    }
    if (is_sorted(v[0].begin(), v[0].end()) && is_sorted(v[1].begin(), v[1].end()))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}