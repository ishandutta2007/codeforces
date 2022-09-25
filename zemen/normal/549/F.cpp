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
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 400001;
const int maxmod = 1000002;

int a[maxn];
int k;

int cnt[maxmod];

int pmax[maxn];
int psum[maxn];

ll get(int l, int r, int c, bool eq)
{
//    cerr << "get " << l << ' ' << r << ' ' << c << '\n';
    ll res = 0;

    pmax[c] = 0;
    psum[c] = 0;
    forab (i, c, r)
    {
        pmax[i + 1] = max(pmax[i], a[i]);
        psum[i + 1] = (psum[i] + a[i]) % k;
    }

    int ptr = c + 1;
    int csum = 0;
    int cmax = 0;
    for (int i = c - 1; i >= l; --i)
    {
        csum = (csum + a[i]) % k;
        cmax = max(cmax, a[i]);
        while (ptr <= r && (pmax[ptr] < cmax || (pmax[ptr] == cmax && eq)))
        {
            cnt[psum[ptr]]++;
            ++ptr;
        }
        int need = (cmax - csum) % k;
        if (need < 0)
            need += k;
        res += cnt[need];
    }

    forab (i, c, r + 1)
        cnt[psum[i]] = 0;

    return res;
}

ll calc(int l, int r)
{
//    cerr << "calc " << l << ' ' << r << '\n';
    if (l + 1 >= r)
    {
//        cerr << "end\n";
        return 0;
    }
    int c = (l + r) / 2;
    ll res = calc(l, c) + calc(c, r);
    res += get(l, r, c, true);
    reverse(a + l, a + r);
    res += get(l, r, l + r - c, false);
    reverse(a + l, a + r);
//    cerr << "end\n";
    return res;
}

int solve()
{
    int n;
    cin >> n >> k;
    forn (i, n)
        cin >> a[i];
    cout << calc(0, n) << '\n';
    return 0;
}