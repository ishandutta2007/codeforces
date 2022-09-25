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
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 300001;

ll a[maxn];
vector <int> g[maxn];
ll b[maxn][2];

void dfs(int u)
{
    ll odd = -INFL, even = 0;
    for (auto v: g[u])
    {
        dfs(v);
        ll odd2 = odd + b[v][0];
        ll even2 = even + b[v][0];
        ll odd3 = even + b[v][1];
        ll even3 = odd + b[v][1];
        odd = max(odd, odd2);
        odd = max(odd, odd3);
        even = max(even, even2);
        even = max(even, even3);
    }
    odd = max(odd, even + a[u]);
    b[u][0] = even;
    b[u][1] = odd;
}

int solve()
{
    int n;
    cin >> n;
    forn (i, n)
    {
        int p, A;
        scanf("%d%d", &p, &A);
        --p;
        a[i] = A;
        if (p >= 0)
            g[p].push_back(i);
    }
    dfs(0);
    ll best = 0;
    forn (i, n)
        best = max(best, max(b[i][0], b[i][1]));
    cout << best << '\n';
    return 0;
}