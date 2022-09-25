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

const int maxn = 2100007;

int d[maxn];

int minp[maxn];
vector<int> pr;
bool ex[maxn];

int solve()
{
    for (int i = 2; i < maxn; ++i)
    {
       if (minp[i] == 0) {
           minp[i] = i;
           pr.push_back(i);
       }

       for (int j = 0; j < sz(pr) && pr[j] <= minp[i] && ll(i) * pr[j] < maxn; ++j)
           minp[i * pr[j]] = pr[j];
    }

    int n;
    cin >> n;
    forn (i, n)
    {
        int c;
        scanf("%d", &c);
        ex[c] = true;
    }
    int res = 0;
    forab (i, 1, maxn)
    {
        d[i] = 0;
        int q = i;
        while (q > 1)
        {
            int p = minp[q];
            d[i] = max(d[i], d[i / p]);
            q /= p;
        }
        d[i] += ex[i];
        res = max(res, d[i]);
    }
    cout << res << '\n';
    return 0;
}