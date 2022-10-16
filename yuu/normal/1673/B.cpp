#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int p[256];
int total = 0;
bool check(const int& l, const int& r) {
    int done = 0;
    for (int i = l; i < r; i++) {
        done |= (1 << (s[i] - 'a'));
    }
    return __builtin_popcount(done) == total;
}

void solve() {
    cin >> s;
    n = s.size();
    s = '0' + s;
    for (int i = 'a'; i <= 'z'; i++) p[i] = 1;
    total = 0;
    for (auto&& x : s) {
        if (p[x]) {
            p[x] = 0;
            total++;
        }
    }
    int close = 0;
    for (int i = 1; i <= n; i++) {
        if (p[s[i]] > close) {
            close = p[s[i]];
            if (!check(close, i)) {
                cout << "NO\n";
                return;
            }
        }
        p[s[i]] = i;
    }
    cout<<"YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}