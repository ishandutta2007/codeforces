#include <bits/stdc++.h>
using namespace std;
string s;
bool f[102];
void solve() {
    cin >> s;
    if (is_sorted(s.begin(), s.end())) {
        cout << "YES\n";
        return;
    }
    s = '0' + s + '1';
    for (int i = 0; i < s.size(); i++) f[i] = 0;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < s.size(); i++) {
        for (int j = i - 2; j > 0; j--) {
            if (f[j] && (s[j - 1] <= s[j + 1])) {
                f[i] = 1;
                break;
            }
            if (s[j] > s[j + 1]) break;
        }
    }
    if (f[s.size() - 1] || f[s.size() - 2])
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}