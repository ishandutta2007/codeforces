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
    freopen("c.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 21;

string s[maxn];
int a[maxn][maxn];

int d[1 << 20];

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
        cin >> s[i];
    forn (i, n)
        forn (j, m)
            cin >> a[i][j];
    fill(d, d + (1 << n), INF);
    d[0] = 0;
    forn (pos, m)
    {
        forn (c, 26)
        {
            vector <int> values;
            int mask = 0;
            forn (i, n)
            {
                if (s[i][pos] != char('a' + c))
                    continue;
                values.push_back(a[i][pos]);
                mask |= (1 << i);
            }
            if (sz(values) < 2)
                continue;
            int cost = accumulate(values.begin(), values.end(), 0);
            cost -= *max_element(values.begin(), values.end());
            forn (Q, 1 << n)
                d[Q | mask] = min(d[Q | mask], d[Q] + cost);
        }
    }
    forn (i, n)
    {
        int cost = *min_element(a[i], a[i] + m);
        forn (j, m)
        {
            bool uniq = true;
            forn (k, n)
                if (i != k)
                    uniq &= (s[i][j] != s[k][j]);
            if (uniq)
                cost = 0;
        }

        int mask = (1 << i);
        forn (Q, 1 << n)
            d[Q | mask] = min(d[Q | mask], d[Q] + cost);
    }
    cout << d[(1 << n) - 1] << '\n';
    return 0;
}