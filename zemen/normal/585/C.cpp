#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 1000000000000001000;
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

ll gcd(ll a, ll b)
{
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

typedef unsigned long long ull;

bool cmp(ll a, ll b, ll c, ll d)
{
    ld f = fabsl((ld) a * b - (ld) c * d);
    if (f > 1e9)
        return (ld) a * b < (ld) c * d;
    ull diff = (ull) a * (ull) b - (ull) c * (ull) d;
    return diff >= INFL * 2;
}

int solve()
{
    ll a, b;
    cin >> a >> b;
    if (gcd(a, b) != 1)
    {
        cout << "Impossible\n";
        return 0;
    }
    ll lp = 0, lq = 1, rp = 1, rq = 0;
    vector<pair<ll, char>> ans;
    while (lp + rp != a || lq + rq != b)
    {
        assert(lp + rp < a || lq + rq < b);
        ll cp = lp + rp;
        ll cq = lq + rq;
        if (cmp(a, cq, b, cp))
        {
            ll LB = 1;
            while (true)
            {
                ll C = LB * 2;
                ll p = lp * C + rp;
                ll q = lq * C + rq;
                if (cmp(a, q, b, p))
                    LB = C;
                else
                    break;
            }
            rp = lp * LB + rp;
            rq = lq * LB + rq;
            if (!ans.empty() && ans.back().second == 'B')
                ans.back().first += LB;
            else
                ans.emplace_back(LB, 'B');
        }
        else
        {
            ll LB = 1;
            while (true)
            {
                ll C = LB * 2;
                ll p = rp * C + lp;
                ll q = rq * C + lq;
                if (cmp(b, p, a, q))
                    LB = C;
                else
                    break;
            }
            lp = rp * LB + lp;
            lq = rq * LB + lq;
            if (!ans.empty() && ans.back().second == 'A')
                ans.back().first += LB;
            else
                ans.emplace_back(LB, 'A');
        }
    }
    for (auto p: ans)
        cout << p.first << p.second;
    cout << '\n';
    assert(lp + rp == a && lq + rq == b);
    return 0;
}