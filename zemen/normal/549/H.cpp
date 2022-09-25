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
    cout.precision(15);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("h.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

ld calcmin(ld a, ld b, ld C)
{
    ld res = a * b;
    res = min(res, (a + C) * (b + C));
    res = min(res, (a - C) * (b - C));
    res = min(res, (a + C) * (b - C));
    res = min(res, (a - C) * (b + C));
    return res;
}

ld calcmax(ld a, ld b, ld C)
{
    ld res = a * b;
    res = max(res, (a + C) * (b + C));
    res = max(res, (a - C) * (b - C));
    res = max(res, (a + C) * (b - C));
    res = max(res, (a - C) * (b + C));
    return res;
}

int solve()
{
    ld a, b, c, d;
    cin >> a >> b >> c >> d;
    
    ld lb = 0, rb = 1e18;
    for (int iter = 0; iter < 300; ++iter)
    {
        ld C = (lb + rb) / 2;
        ld mindet = calcmin(a, d, C) + calcmin(b, -c, C);
        ld maxdet = calcmax(a, d, C) + calcmax(b, -c, C);
        if (mindet <= 0 && maxdet >= 0)
            rb = C;
        else
            lb = C;
    }
    cout << lb << '\n';
    return 0;
}