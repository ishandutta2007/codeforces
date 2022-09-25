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
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 100100;
int x[maxn], y[maxn];
int a = 0, b = 1, c = 2;

ll sq(int a, int b, int c)
{
    ll x1 = x[a] - x[c];
    ll y1 = y[a] - y[c];
    ll x2 = x[b] - x[c];
    ll y2 = y[b] - y[c];
    return llabs(x1 * y2 - x2 * y1);
}

bool inside(int i)
{
    return sq(a, b, i) + sq(a, c, i) + sq(b, c, i) == sq(a, b, c);
}



int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> x[i] >> y[i];
    for (c = 2; c < n; ++c)
    {
        if (sq(a, b, c) > 0)
            break;
    }
    assert(c < n);
    forn (i, n)
    {
        if (i != a && i != b && i != c && inside(i))
        {
            if (sq(a, b, i) > 0)
                c = i;
            else if (sq(a, c, i) > 0)
                b = i;
            else
                a = i;
        }
    }
    forn (i, n)
        if (i != a && i != b && i != c)
            assert(!inside(i));
    assert(sq(a, b, c) > 0);
    assert(a != b);
    assert(c != b);
    assert(a != c);
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
    return 0;
}