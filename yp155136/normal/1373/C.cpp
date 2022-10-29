#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void go() {
    string s; cin >> s;
    int n = (int)s.size();
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '+') {
            ++cur;
        }
        else {
            --cur;
            if (cur < 0) {
                ans += (i + 1);
                ++cur;
            }
        }
    }
    cout << ans + n << endl;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        go();
    }
}