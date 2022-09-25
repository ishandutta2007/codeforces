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

vector<int> getPrimes(int n)
{
    vector<int> res;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res.push_back(n);
    return res;
}

const int maxn = 2e6;
int x[maxn];
ll d[maxn][3];
ll A, B;

ll divideCost(int n, int p)
{
    if (n % p == 0)
        return 0;
    if ((n + 1) % p == 0)
        return B;
    if ((n - 1) % p == 0)
        return B;
    return INFL;
}

void uin(ll &a, ll b)
{
    a = min(a, b);
}

int solve()
{
    int n;
    cin >> n >> A >> B;
    forn (i, n)
        scanf("%d", x + i);
    set<int> S;
    int num[6] = {x[0] - 1, x[0], x[0] + 1, x[n - 1] - 1, x[n - 1], x[n - 1] + 1};
    for (int X: num)
    {
        vector<int> s2 = getPrimes(X);
        for (int p: s2)
            S.insert(p);
    }
    ll res = INFL;
    for (auto p: S)
    {
//        cerr << "PRIME " << p << '\n';
        forn (iter, 2)
        {
            forn (i, n + 1)
                forn (j, 3)
                    d[i][j] = INFL;
            d[1][0] = divideCost(x[0], p);

            forab (i, 1, n + 1)
                forn (state, 3)
                {
                    if (d[i][state] == INFL)
                        continue;
                    forab (to, state + 1, 3)
                        uin(d[i][to], d[i][state]);
                    if (i == n)
                        continue;
                    if (state != 1)
                        uin(d[i + 1][state], d[i][state] + divideCost(x[i], p));
                    else
                        uin(d[i + 1][state], d[i][state] + A);
                }
            res = min(res, d[n][2]);
            reverse(x, x + n);
        }
    }
    cout << res << '\n';
    return 0;
}