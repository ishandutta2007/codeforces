#include <bits/stdc++.h>
using namespace std;
string s;
bool check(int mask) {
    int cnt = 0;
    for (char c : s) {
        c = ")("[(mask >> (c - 'A')) & 1];
        if (c == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}
void solve() {
    cin >> s;
    for (int i = 0; i < 8; i++)
        if (check(i)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}