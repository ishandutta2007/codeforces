#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    char move;
    if (x > y) move = 'E';
    else move = 'N';
    string ans;
    while (x || y) {
        if (x < 0 || y < 0) break;
        ans += move;
        if (move == 'N') {
            y--;
            if (x) move = 'E';
            else move = '0';
        } else if (move == 'E') {
            x--;
            if (y) move = 'N';
            else move = '0';
        } else {
            if (x) move = 'E';
            else move = 'N';
        }
    }
    cout << ans.size() << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}