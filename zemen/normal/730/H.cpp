#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

string s[105];
bool del[105];

string t;

int main() {
    #ifdef LOCAL
    assert(freopen("h.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    forn (i, n)
        cin >> s[i];
    forn (i, m) {
        int x;
        cin >> x;
        --x;
        del[x] = true;
        if (i == 0)
            t = s[x];
        else {
            if (sz(s[x]) != sz(t)) {
                cout << "No\n";
                return 0;
            }
            forn (j, sz(t)) {
                if (t[j] != s[x][j])
                    t[j] = '?';
            }
        }
    }
    forn (i, n) {
        if (del[i])
            continue;
        if (sz(s[i]) != sz(t))
            continue;
        bool fail = true;
        forn (j, sz(t)) {
            if (t[j] == '?')
                continue;
            if (t[j] != s[i][j])
                fail = false;
        }
        if (fail) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    cout << t << '\n';
}