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

const int maxn = 550;
int a[maxn][maxn];
int p[maxn];

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        forn (j, n)
            cin >> a[i][j];
    forn (i, n)
        p[i] = -1;
    int rem = n - 1;
    while (rem)
    {
        forn (i, n)
        {
            if (p[i] != -1)
                continue;
            vector<int> q;
            forn (j, n)
            {
                if (j == i)
                    continue;
                if (p[j] != -1)
                    continue;
                q.push_back(a[i][j]);
            }
            bool ok = true;
            forn (j, sz(q) - 1)
                if (q[j] != q[j + 1])
                    ok = false;
            if (!ok)
                continue;
            p[i] = q[0];
            --rem;
            if (!rem)
                break;
        }
    }
    forn (i, n)
        if (p[i] == -1)
            p[i] = n;
    forn (i, n)
        cout << p[i] << ' ';
    cout << '\n';
    return 0;
}