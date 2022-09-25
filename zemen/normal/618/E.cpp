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

typedef complex<ld> pt;

const int base = 1 << 19;
pt t[base * 2];
pt upd[base * 2];

void push(int v)
{
    t[v * 2] *= upd[v];
    t[v * 2 + 1] *= upd[v];
    upd[v * 2] *= upd[v];
    upd[v * 2 + 1] *= upd[v];
    upd[v] = 1;
}

pt sum(int l, int r, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return 0;
    push(v);
    int cc = (cl + cr) / 2;
    return sum(l, r, v * 2, cl, cc) + sum(l, r, v * 2 + 1, cc, cr);
}

void prolong(int pos, int val, int v = 1, int cl = 0, int cr = base)
{
    if (cl + 1 == cr)
    {
        assert(pos == cl);
        t[v] += t[v] / abs(t[v]) * ld(val);
        return;
    }
    push(v);
    int cc = (cl + cr) / 2;
    if (pos < cc)
        prolong(pos, val, v * 2, cl, cc);
    else
        prolong(pos, val, v * 2 + 1, cc, cr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void rot(int l, int r, pt ang, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
    {
        t[v] *= ang;
        upd[v] *= ang;
        return;
    }
    if (r <= cl || cr <= l)
        return;
    push(v);
    int cc = (cl + cr) / 2;
    rot(l, r, ang, v * 2, cl, cc);
    rot(l, r, ang, v * 2 + 1, cc, cr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, n)
        t[i + base] = 1;
    forab (i, n, base)
        t[i + base] = 0;
    for (int i = base - 1; i > 0; --i)
        t[i] = t[i * 2] + t[i * 2 + 1];
    forn (i, 2 * base)
        upd[i] = 1;
    ld PI = acosl(-1);
    forn (i, m)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1)
            prolong(y - 1, z);
        else
        {
            z = 360 - z;
            rot(y - 1, n, polar(ld(1), ld(z / 180.0 * PI)));
        }
//        pt res = sum(0, n);
        pt res = t[1];
        cout << res.real() << ' ' << res.imag() << '\n';
    }
    return 0;
}