#include <bits/stdc++.h>
using namespace std;
vector<int> a[2];
void solve() {
    for (int i = 0, n; i < 2; i++) {
        cin >> n;
        a[i].resize(n);
        for (auto&& x : a[i]) cin >> x;
        sort(a[i].begin(), a[i].end());
    }
    if (a[0].back() >= a[1].back()) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    if (a[1].back() >= a[0].back()) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}