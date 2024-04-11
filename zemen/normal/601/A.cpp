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
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 405;
int a[maxn][maxn];
int dist[maxn];

int solve()
{
    int n, m;
    cin >> n >> m;
    forn (i, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        a[u][v] = a[v][u] = 1;
    }
    if (a[0][n - 1] == 1)
    {
        forn (i, n)
            forn (j, n)
                a[i][j] ^= 1;
    }
    fill(dist, dist + n, INF);
    dist[0] = 0;
    queue<int> o;
    o.push(0);
    while (!o.empty())
    {
        int u = o.front();
        o.pop();
        if (u == n - 1)
        {
            cout << dist[u] << '\n';
            return 0;
        }
        forn (v, n)
        {
            if (!a[u][v])
                continue;
            if (dist[v] != INF)
                continue;
            dist[v] = dist[u] + 1;
            o.push(v);
        }
    }
    cout << -1 << '\n';
    return 0;
}