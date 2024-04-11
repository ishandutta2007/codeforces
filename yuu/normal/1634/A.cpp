#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 0) {
        cout << "1\n";
        return;
    }
    string t = s;
    reverse(t.begin(), t.end());
    cout << "12"[t != s] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}