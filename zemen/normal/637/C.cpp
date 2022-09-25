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

const int maxn = 1010;
int n;
string s[maxn];

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif

    int n;
    cin >> n;
    forn (i, n)
        cin >> s[i];
    int worst = 13;
    forn (i, n)
        forn (j, i) {
            int cur = 0;
            forn (q, 6)
                cur += s[i][q] != s[j][q];
            worst = min(worst, cur);
        }
    cout << (worst - 1) / 2 << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}