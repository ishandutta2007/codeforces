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
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1005;
char s[3][maxn];
bool d[maxn][3];

bool can(int i, int j, int nj)
{
    int ri = i * 3;
    assert(s[j][ri] == '.');
    if (s[j][ri + 1] != '.')
        return false;
    if (s[nj][ri + 1] != '.')
        return false;
    if (s[nj][ri + 2] != '.' || s[nj][ri + 3] != '.')
        return false;
    return true;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    forn (i, 3)
    {
        fill(s[i], s[i] + maxn, '.');
        forn (j, maxn)
            d[j][i] = false;
    }
    forn (i, 3)
    {
        scanf("%s", s[i]);
        s[i][n] = '.';
    }
    int pos = 0;
    while (s[pos][0] != 's')
        ++pos;
    s[pos][0] = '.';
    d[0][pos] = true;
    forn (i, n - 1)
        forn (j, 3)
        {
            if (!d[i][j])
                continue;
            forab (dj, -1, 2)
            {
                if (j + dj < 0 || j + dj >= 3)
                    continue;
                if (!can(i, j, j + dj))
                    continue;
                d[i + 1][j + dj] = true;
            }
        }
    if (d[n - 1][0] || d[n - 1][1] || d[n - 1][2])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}