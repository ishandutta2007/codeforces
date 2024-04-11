#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)

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

const ll magic = 10000;

int solve()
{
    ll c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    if (wb > magic)
    {
        swap(wb, wr);
        swap(hb, hr);
    }
    if (wr > magic)
    {
        ll res = 0;
        ll a = 0, b = c / wb;
        res = b * hb;
        while (true)
        {
            ++a;
            if (wr * a > c)
                break;
            b = (c - wr * a) / wb;
            if (b < 0)
                break;
            res = max(res, a * hr + b * hb);
        }
        cout << res << '\n';
        return 0;
    }
    if (hr * wb > hb * wr)
    {
        swap(wb, wr);
        swap(hb, hr);
    }
    ll a = 0, b = c / wb;
    ll res = 0;
    res = b * hb;
    forn (i, wb)
    {
        ++a;
        if (wr * a > c)
            break;
        b = (c - wr * a) / wb;
        if (b < 0)
            break;
        res = max(res, a * hr + b * hb);
    }
    cout << res << '\n';
    return 0;
}