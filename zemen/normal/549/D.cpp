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
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 200;

string s[maxn];

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
    {
        cin >> s[i];
        s[i] += 'E';
    }
    forn (i, m + 1)
        s[n] += 'E';
    int ans = 0;
    forn (i, n)
        forn (j, m)
        {
            if (s[i][j] == s[i][j + 1] && s[i + 1][j] == s[i + 1][j + 1])
                continue;
            if (s[i][j] == s[i + 1][j] && s[i][j + 1] == s[i + 1][j + 1])
                continue;
            ++ans;
        }
    cout << ans << '\n';
    return 0;
}