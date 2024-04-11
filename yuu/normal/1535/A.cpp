#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s[4];
    for (int i = 0; i < 4; i++) cin >> s[i];
    int w[2] = {max(s[0], s[1]), max(s[2], s[3])};
    sort(s, s + 4);
    reverse(s, s + 4);
    sort(w, w + 2);
    reverse(w, w + 2);
    if (s[1] == w[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}