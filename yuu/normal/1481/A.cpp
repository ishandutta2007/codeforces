#include <bits/stdc++.h>
using namespace std;

int x, y;
string s;
void solve() {
    cin >> x >> y >> s;
    char y_c = 'U';
    if (y < 0) {
        y = -y;
        y_c = 'D';
    }
    char x_c = 'R';

    if (x < 0) {
        x = -x;
        x_c = 'L';
    }
    for (auto&& c : s) {
        if (c == y_c) y--;
        else if (c == x_c) x--;
    }
    if ((x <= 0) && (y <= 0)) {
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