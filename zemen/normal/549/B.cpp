#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1000;

string s[maxn];
bool ok[maxn];
int cnt[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> s[i];
    forn (i, n)
        cin >> cnt[i];
    bool ch = true;
    while (ch)
    {
        ch = false;
        forn (i, n)
            if (cnt[i] == 0)
            {
                int coef = ok[i] ? 1 : -1;
                forn (j, n)
                    cnt[j] += coef * (s[i][j] - '0');
                ok[i] ^= 1;
                ch = true;
            }
    }
    int res = 0;
    forn (i, n)
        res += ok[i];
    cout << res << '\n';
    forn (i, n)
        if (ok[i])
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}