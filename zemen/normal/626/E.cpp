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
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 200200;
int a[maxn];
ll pr[maxn];

ll get(int l, int r)
{
    return pr[r] - pr[l];
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    sort(a, a + n);
    forn (i, n)
        pr[i + 1] = pr[i] + a[i];

    ll best = -INFL;
    int besti = -1, bestk = -1;

    int ck = 0;
    forn (i, n)
    {
        while (ck + i + 1 > n)
            --ck;
        while (ck && ll(a[n - ck] + a[i - ck]) * (2 * ck + 1) < (get(i - ck, i + 1) + get(n - ck, n)) * 2)
            --ck;
        ll cres = get(i - ck, i + 1) + get(n - ck, n);
        cres -= ll(a[i]) * (ck * 2 + 1);
        if (besti == -1 || (cres * (2 * bestk + 1) > best * (2 * ck + 1)))
        {
            besti = i;
            best = cres;
            bestk = ck;
        }
        ++ck;
    }
    assert(besti != -1);
    cout << bestk * 2 + 1 << '\n';
    for (int i = bestk; i >= 0; --i)
        cout << a[besti - i] << ' ';
    for (int i = bestk - 1; i >= 0; --i)
        cout << a[n - i - 1] << ' ';
    cout << '\n';
    return 0;
}