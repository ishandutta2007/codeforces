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
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 500500;

int a[maxn];
int b[maxn];

int res = 0;

void norm(int l, int r)
{
    int len = r - l;
    res = max(res, (len + 1) / 2);
    if (len % 2 == 1)
    {
        forab (i, l, r)
            b[i] = a[l - 1];
    }
    else
    {
        int c = (l + r) / 2;
        forab (i, l, c)
            b[i] = a[l - 1];
        forab (i, c, r)
            b[i] = a[r];
    }
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        scanf("%d", a + i);
    forn (i, n)
        b[i] = a[i];
    int l = 1;
    forab (i, 1, n - 1)
    {
        if (a[i] != a[i - 1] && a[i] != a[i + 1])
            continue;
        norm(l, i);
        l = i + 1;
    }
    if (l < n - 1)
        norm(l, n - 1);
    cout << res << '\n';
    forn (i, n)
        cout << b[i] << ' ';
    cout << '\n';
    return 0;
}