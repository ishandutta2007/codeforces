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

const int maxn = 3005;

vector <int> g[maxn];
int s[2], t[2], l[2];
int dist[maxn][maxn];
int n;

void bfs(int u, int dist[])
{
    fill(dist, dist + n, INF);
    dist[u] = 0;
    queue <int> o;
    o.push(u);
    while (!o.empty())
    {
        u = o.front();
        o.pop();
        for (int v: g[u])
        {
            if (dist[v] <= dist[u] + 1)
                continue;
            dist[v] = dist[u] + 1;
            o.push(v);
        }
    }
}

int solve()
{
    int m;
    cin >> n >> m;
    forn (i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    forn (i, 2)
    {
        cin >> s[i] >> t[i] >> l[i];
        --s[i], --t[i];
    }
    forn (i, n)
        bfs(i, dist[i]);
    int ans = -1;
    if (dist[s[0]][t[0]] <= l[0] && dist[s[1]][t[1]] <= l[1])
        ans = (m - dist[s[0]][t[0]] - dist[s[1]][t[1]]);
    forn (i, n)
        forn (j, n)
        {
            int d1 = dist[i][s[0]] + dist[i][j] + dist[j][t[0]];
            int d2 = dist[i][s[1]] + dist[i][j] + dist[j][t[1]];
            if (d1 > l[0] || d2 > l[1])
                continue;
            int d = d1 + d2 - dist[i][j];
            ans = max(ans, m - d);
        }
    swap(s[0], t[0]);
    forn (i, n)
        forn (j, n)
        {
            int d1 = dist[i][s[0]] + dist[i][j] + dist[j][t[0]];
            int d2 = dist[i][s[1]] + dist[i][j] + dist[j][t[1]];
            if (d1 > l[0] || d2 > l[1])
                continue;
            int d = d1 + d2 - dist[i][j];
            ans = max(ans, m - d);
        }
    cout << ans << '\n';
    return 0;
}