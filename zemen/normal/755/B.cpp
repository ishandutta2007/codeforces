#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

char s[505];
int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    vector<string> S;
    forn (i, n) {
        scanf("%s", s);
        S.push_back(s);
    }
    sort(S.begin(), S.end());
    int k = 0;
    forn (i, m) {
        scanf("%s", s);
        int pos = lower_bound(S.begin(), S.end(), s) - S.begin();
        if (pos < sz(S) && S[pos] == s)
            ++k;
    }
    //cerr << k << '\n';
    n -= k, m -= k;
    for (int turn = 0; ; turn ^= 1) {
        if (k)
            --k;
        else {
            if (turn == 0 && n)
                --n;
            else if (turn == 1 && m)
                --m;
            else {
                cout << (turn ? "YES" : "NO") << '\n';
                break;
            }
        }
    }
}