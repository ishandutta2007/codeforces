#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MOD = (int) 998244353;
const int maxn = (int) 1e6 + 20;

int n, m;
vector< tuple<int, int, int> > edge;
vector< vector<int> > G;
int used[maxn];
int fa[maxn];
int find_fa(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = find_fa(fa[x]);
}

int uni(int x, int y)
{
    x = find_fa(x);
    y = find_fa(y);
    if(x == y) return 0;
    return fa[x] = y;
}

int up[55];
LL F[55][55];
int du[maxn];

LL dis[maxn];
int dep[maxn];


int eu[maxn << 1];
int g[maxn];
int clk;
void dfs(int u, int pre)
{
    eu[++clk] = u;
    g[u] = clk;

    for(const auto q : G[u])
    {
        const auto &e = edge[q];
        int x, y, z;
        tie(x, y, z) = e;
        int v = x + y - u;
        if(v == pre) continue;
        dis[v] = dis[u] + z;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        eu[++clk] = u;
    }
}

int lg[maxn << 1];
struct LCA
{
    int n;
    int p[20][maxn << 1];

    void init(int _n, int *arr)
    {
        n = _n;
        for(int i = 1; i <= n; i++) p[0][i] = arr[i];
    }

    inline int get_min(int x, int y)
    {
        return dep[x] < dep[y] ? x : y;
    }

    void preprocessing()
    {
        for(int j = 1; j <= lg[n]; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                p[j][i] = get_min(p[j - 1][i], p[j - 1][i + (1 << (j - 1))]);
    }

    int query(int x, int y)
    {
        if(x > y) swap(x, y);
        int c = lg[y - x + 1];
        return get_min(p[c][x], p[c][y - (1 << c) + 1]);
    }
}lca;

LL treeDist(int x, int y)
{
    int pre = lca.query(g[x], g[y]);
    return dis[x] + dis[y] - (dis[pre] << 1);
}

void work()
{
    scanf("%d%d", &n, &m);

    lg[1] = 0;
    for(int i = 2; i <= (n << 1); i++)
        lg[i] = lg[i - 1] + !(i & (i - 1));

    edge = vector< tuple<int, int, int> > (m);
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edge[i] = make_tuple(x, y, z);
    }

    for(int i = 1; i <= n; i++) fa[i] = i;

    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        tie(x, y, z) = edge[i];
        if(uni(x, y))
            used[i] = 1;
    }
    G = vector< vector<int> > (n + 1);

    memset(F, 0x3f, sizeof(F));

    int ucnt = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        tie(x, y, z) = edge[i];
        if(used[i])
        {
            G[x].push_back(i);
            G[y].push_back(i);
        }
        else
        {
//            cout <<x <<" " <<y <<" " <<z <<endl;
            up[ucnt << 1] = x;
            up[ucnt << 1 | 1] = y;
            F[ucnt << 1][ucnt << 1 | 1] = F[ucnt << 1 | 1][ucnt << 1] = z;
            ucnt++;
        }
    }

    clk = 0;
    dfs(1, 1);
    lca.init(clk, eu);
    lca.preprocessing();

    for(int i = 0; i < ucnt * 2; i++)
        for(int j = 0; j < ucnt * 2; j++)
            F[i][j] = min(F[i][j], treeDist(up[i], up[j]));

    for(int k = 0; k < ucnt * 2; k++)
        for(int i = 0; i < ucnt * 2; i++)
            for(int j = 0; j < ucnt * 2; j++)
                F[i][j] = min(F[i][j], F[i][k] + F[k][j]);

    int Q; scanf("%d", &Q);
    while(Q--)
    {
        int x, y; scanf("%d%d", &x, &y);
        LL ans = treeDist(x, y);
        for(int i = 0; i < ucnt * 2; i++)
            for(int j = 0; j < ucnt * 2; j++)
                ans = min(ans, F[i][j] + treeDist(x, up[i]) + treeDist(y, up[j]));
        printf("%lld\n", ans);
    }
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    work();
    return 0;
}