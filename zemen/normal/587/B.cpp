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

const int maxn = 3e6;
int a[maxn];
int rem[maxn];
int fin[maxn];
int d[maxn];
int minid[maxn];

const int mod = int(1e9) + 7;

int sum(int a, int b)
{
    return (a + b) % mod;
}

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

void add(int &a, int b)
{
    a += b;
    a %= mod;
}

int solve()
{
    int n, k;
    ll l;
    cin >> n >> l >> k;
    forn (i, n)
        scanf("%d", a + i);
    forn (i, l % n)
        rem[i] = a[i];
    sort(a, a + n);
    int id = 0;
    forn (i, n)
    {
        if (a[i] != a[id])
            id = i;
        minid[i] = id;
    }

    sort(rem, rem + l % n);
    forn (i, n)
        fin[i] = l % n - (lower_bound(rem, rem + l % n, a[i]) - rem);
    d[0] = 1;
    ll blocks = l / n;
    int res = 0;
    forn (i, k)
    {
//        cerr << "LEN " << i + 1 << '\n';
        int s = 0;
        forn (j, n)
        {
            add(s, d[i * n + j]);
            add(d[(i + 1) * n + minid[j]], s);
            if (i < blocks)
            {
                add(res, mul(s, (blocks - i) % mod));
//                cerr << mul(s, (blocks - i) % mod) << '\n';
            }
            if (i <= blocks)
            {
                add(res, mul(fin[j], d[i * n + j]));
//                cerr << mul(fin[j], d[i * n + j]) << '\n';
            }
        }
    }
    cout << res << '\n';
    return 0;
}