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

const int maxn = 300;
int f[maxn];
bool used[maxn];

typedef unsigned long long big;

big res = 1;

big gcd(big a, big b)
{
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

void upd_res(big c)
{
    if (c == 0)
        return;
    res = (res / gcd(res, c)) * c;
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
    {
        cin >> f[i];
        --f[i];
    }
    int minr = 1;
    forn (i, n)
    {
//        cerr << i << '\n';
        fill(used, used + n, false);
        vector <int> s(0);
        int u = i;
        int len = 0;
        while (!used[u])
        {
            s.push_back(u);
            used[u] = true;
            u = f[u];
            ++len;
        }
        int cycle = 1;
        while (s.back() != u)
        {
            s.pop_back();
            ++cycle;
        }
        int pre = len - cycle;
//        cerr << cycle << ' ' << pre << '\n';
        minr = max(minr, pre);
        upd_res(cycle);
    }
    big ans = res;
    while (ans < (big) minr)
        ans += res;
    cout << ans << '\n';
    return 0;
}