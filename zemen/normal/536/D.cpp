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
    freopen("d.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 2101;
vector<pair<int, int>> g[maxn];
int cost[maxn];

ll dist[2][maxn];
bool used[maxn];

void dijkstra(int n, ll *dist, int s)
{
    fill(dist, dist + n, INFL);
    fill(used, used + n, false);
    dist[s] = 0;
    forn (i, n)
    {
        int u = -1;
        forn (v, n)
            if (!used[v] && (u == -1 || dist[v] < dist[u]))
                u = v;
        used[u] = true;
        for (auto e: g[u])
        {
            int v = e.first, w = e.second;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
}

vector <ll> coord[2];

int compress(ll val, int id)
{
    assert(binary_search(coord[id].begin(), coord[id].end(), val));
    return lower_bound(coord[id].begin(), coord[id].end(), val) - coord[id].begin();
}

ll a[maxn][maxn];
ll sum[maxn][maxn];
bool exist[maxn][maxn];
int has[maxn][maxn];

ll score[maxn][maxn][2];
int best_move[maxn][maxn][2];
int next_valid[maxn][maxn][2];

ll calc(int x, int y, int who)
{
    ll &res = score[x][y][who];
    if (res != INFL)
        return res;
    if (has[x][y] == 0)
        return res = 0;
//    cerr << x << ' ' << y << ' ' << who << '\n';
    int &bm = best_move[x][y][who];
    int &nv = next_valid[x][y][who];
    if (who == 0)
    {
        calc(x - 1, y, who);
        nv = next_valid[x - 1][y][who];
        if (has[x][y] != has[x - 1][y])
            nv = x - 1;
        bm = best_move[nv][y][who];
        ll s1 = calc(bm, y, who ^ 1) + (sum[x][y] - sum[bm][y]);
        ll s2 = calc(nv, y, who ^ 1) + (sum[x][y] - sum[nv][y]);
        if (s2 > s1)
            bm = x - 1;
        res = max(s1, s2);
        return res;
    }
    else
    {
        assert(who == 1);
        calc(x, y - 1, who);
        nv = next_valid[x][y - 1][who];
        if (has[x][y] != has[x][y - 1])
            nv = y - 1;
        bm = best_move[x][nv][who];
        ll s1 = calc(x, bm, who ^ 1) - (sum[x][y] - sum[x][bm]);
        ll s2 = calc(x, nv, who ^ 1) - (sum[x][y] - sum[x][nv]);
        if (s2 < s1)
            bm = y - 1;
        res = min(s1, s2);
        return res;
    }
}

int solve()
{
    int n, m;
    int s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    forn (i, n)
        scanf("%d", cost + i);
    forn (i, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dijkstra(n, dist[0], s);
    dijkstra(n, dist[1], t);
    forn (i, 2)
        forn (j, n)
            coord[i].push_back(dist[i][j]);
    forn (i, 2)
    {
        sort(coord[i].begin(), coord[i].end());
        coord[i].erase(unique(coord[i].begin(), coord[i].end()), coord[i].end());
    }
    forn (u, n)
    {
        int x = compress(dist[0][u], 0);
        int y = compress(dist[1][u], 1);
        assert(x < n && y < n);
        a[n - 1 - x][n - 1 - y] += cost[u];
        exist[n - 1 - x][n - 1 - y] = true;
    }
//    forn (i, n)
//    {
//        forn (j, n)
//            cerr << a[i][j] << ' ';
//        cerr << '\n';
//    }
    forn (i, n)
        forn (j, n)
        {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
            has[i + 1][j + 1] = has[i][j + 1] + has[i + 1][j] - has[i][j] + exist[i][j];
        }
    forn (i, n + 1)
        forn (j, n + 1)
            forn (k, 2)
                score[i][j][k] = INFL;
    ll ans = calc(n, n, 0);
//    cerr << ans << '\n';
    if (ans > 0)
        cout << "Break a heart\n";
    else if (ans < 0)
        cout << "Cry\n";
    else
        cout << "Flowers\n";
    return 0;
}