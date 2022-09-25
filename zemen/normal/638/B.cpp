#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100;
int nx[maxn];
bool used[maxn];
bool nfirst[maxn];

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif

    int n;
    cin >> n;
    forn (i, 26)
        nx[i] = -1;
    forn (i, n) {
        string s;
        cin >> s;
        for (char c: s)
            used[c - 'a'] = true;
        forn (j, sz(s) - 1) {
            nx[s[j] - 'a'] = s[j + 1] - 'a';
            nfirst[s[j + 1] - 'a'] = true;
        }
    }
    forn (i, 26)
        if (used[i] && !nfirst[i]) {
            int u = i;
            while (u != -1) {
                cout << char(u + 'a');
                u = nx[u];
            }
        }
    cout << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}