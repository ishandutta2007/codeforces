#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> l, r;
void solve() {
    cin >> n >> a >> b;
    if (a > n / 2 + 1) {
        cout << "-1\n";
        return;
    }
    if (b < n / 2) {
        cout << "-1\n";
        return;
    }
    l.clear();
    r.clear();
    l.push_back(a);
    r.push_back(b);
    for (int i = 1; i < a; i++)
        if (i != b) r.push_back(i);
    for (int i = b + 1; i <= n; i++)
        if (i != a) l.push_back(i);
    for (int i = a + 1; i < b; i++) {
        if (l.size() > r.size())
            r.push_back(i);
        else
            l.push_back(i);
    }
    if (l.size() != r.size()) {
        cout << "-1\n";
        return;
    }
    for (auto&& x : l) cout << x << ' ';
    for (auto&& x : r) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}