#include <bits/stdc++.h>
using namespace std;
int n;
char c;
string s;
void solve() {
    cin >> n >> c >> s;
    for (int period = 1; period <= n; period++) {
        for (int j = period; j <= n; j += period) {
            if (s[j - 1] != c) goto next_p;
        }
        if (period == 1) {
            cout << "0\n";
        } else {
            cout << "1\n" << period << '\n';
        }
        return;
    next_p:;
    }
    cout << "2\n" << n - 1 << ' ' << n << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}