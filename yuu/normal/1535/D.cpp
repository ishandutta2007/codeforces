#include <bits/stdc++.h>
using namespace std;
int k;
string s;
int f[1 << 18];
int if_win[1 << 18];
vector<int> from[1 << 18];
void solve() {
    cin >> k >> s;
    s = '0' + s;
    int done = 0;
    for (int level = k - 1; level > 0; level--) {
        int first = done + 1;
        int last = done + (1 << level);
        int next_game = last + 1;
        for (int i = first; i <= last; i++) {
            from[next_game].push_back(i);
            if_win[i] = next_game;
            if (from[next_game].size() == 2) next_game++;
        }
        done = last;
    }

    for (int i = 1; i < (1 << k); i++) {
        if (from[i].empty()) {
            f[i] = (s[i] == '?') ? 2 : 1;
        } else {
            if (s[i] == '?')
                f[i] = f[from[i][0]] + f[from[i][1]];
            else
                f[i] = f[from[i][s[i] - '0']];
        }
    }

    int q;
    cin >> q;
    for (int cnt = 1, i; cnt <= q; cnt++) {
        cin >> i;
        char c;
        cin >> c;
        s[i] = c;
        while (i) {
            if (from[i].empty()) {
                f[i] = (s[i] == '?') ? 2 : 1;
            } else {
                if (s[i] == '?')
                    f[i] = f[from[i][0]] + f[from[i][1]];
                else
                    f[i] = f[from[i][s[i] - '0']];
            }
            i = if_win[i];
        }
        cout << f[(1 << k) - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}