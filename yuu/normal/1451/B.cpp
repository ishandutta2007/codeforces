#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
void solve() {
    cin >> n >> q >> s;
    s = 'x' + s;
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        for (int split = l + 1; split <= r; split++) {
            string left = s.substr(l, split - l);
            string right = s.substr(split, r - split + 1);
            int pos = s.find(left);
            if (s.find(right, pos + left.size() + 1) != -1) {
                cout << "YES\n";
                goto next_i;
            }
        }
        cout << "NO\n";
    next_i:;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}