#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1023, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int n, n2;
int a[N][N];
vector<pii> matching;
int matching_id[N];
bool conflict[N][N];
int G[N][N][2][2];

vector<int> latin;
vector<int> g[N];

int match[N], p[N], base[N], q[N];
bool used[N], blossom[N];

int USED[N], COL[N], timer;
int ANS[N];

bool check(int v, int col, int timer, bool mark)
{
    if (USED[v] == timer)
        return COL[v] == col;
    USED[v] = timer;
    COL[v] = col;
    if (mark)
        ANS[v] = col + 1;
    bool res = true;
    for (int to = 0; to < n; to++)
    {
        if (v == to || G[v][to] == 0)
            continue;
        if (!G[v][to][col][0] && !G[v][to][col][1])
            continue;
        if (G[v][to][col][0] && G[v][to][col][1])
            return false;
        if (!G[v][to][col][0])
            res &= check(to, 0, timer, mark);
        if (!G[v][to][col][1])
            res &= check(to, 1, timer, mark);
    }
    return res;
}
void mark_path(int v, int b, int children)
{
    while (base[v] != b)
    {
        blossom[base[v]] = blossom[base[match[v]]] = true;
        p[v] = children;
        children = match[v];
        v = p[match[v]];
    }
}
int lca(int a, int b)
{
    bool used[N] = {0};
    for (;;)
    {
        a = base[a];
        used[a] = true;
        if (match[a] == -1)
            break;
        a = p[match[a]];
    }
    for (;;)
    {
        b = base[b];
        if (used[b])
            return b;
        b = p[match[b]];
    }
}

int find_path(int root)
{
    memset(used, 0, sizeof used);
    memset(p, -1, sizeof p);
    for (int i = 0; i < n2; ++i)
        base[i] = i;

    used[root] = true;
    int qh = 0, qt = 0;
    q[qt++] = root;
    while (qh < qt)
    {
        int v = q[qh++];
        for (size_t i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (base[v] == base[to] || match[v] == to)
                continue;
            if (to == root || match[to] != -1 && p[match[to]] != -1)
            {
                int curbase = lca(v, to);
                memset(blossom, 0, sizeof blossom);
                mark_path(v, curbase, to);
                mark_path(to, curbase, v);
                for (int i = 0; i < n2; ++i)
                    if (blossom[base[i]])
                    {
                        base[i] = curbase;
                        if (!used[i])
                        {
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
            }
            else if (p[to] == -1)
            {
                p[to] = v;
                if (match[to] == -1)
                    return to;
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}

void edmonds()
{
    memset(match, -1, sizeof match);
    for (int i = 0; i < n2; ++i)
        if (match[i] == -1)
        {
            int v = find_path(i);
            while (v != -1)
            {
                int pv = p[v], ppv = match[pv];
                match[v] = pv, match[pv] = v;
                v = ppv;
            }
        }
    return;
}

void solve()
{
    timer = 0;
    matching.clear();
    memset(matching_id, 0, sizeof matching_id);
    for (int i = 0; i < N; i++)
        g[i].clear();
    memset(used, 0, sizeof used);
    memset(blossom, 0, sizeof blossom);
    memset(match, 0, sizeof match);
    memset(base, 0, sizeof base);
    memset(p, 0, sizeof p);
    memset(q, 0, sizeof q);
    memset(USED, 0, sizeof USED);
    memset(COL, 0, sizeof COL);
    memset(ANS, 0, sizeof ANS);

    scanf("%d", &n);
    n2 = n + n;
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n2; j++)
        {
            conflict[i][j] = 0;
            for (int q = 0; q < n; q++)
                if (a[i][q] == a[j][q])
                {
                    g[i].pb(j);
                    g[j].pb(i);
                    conflict[i][j] = 1;
                    break;
                }
        }

    edmonds();
    for (int i = 0; i < n2; i++)
    {
        assert(match[i] != -1);
        if (i < match[i])
            matching.pb({i, match[i]});
    }
    for (int i = 0; i < n; i++)
    {
        int v = matching[i].f;
        int u = matching[i].s;
        matching_id[v] = i;
        matching_id[u] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a = matching[i].f;
            int b = matching[i].s;
            int c = matching[j].f;
            int d = matching[j].s;
            G[i][j][0][0] = conflict[a][c];
            G[i][j][0][1] = conflict[a][d];
            G[i][j][1][0] = conflict[b][c];
            G[i][j][1][1] = conflict[b][d];
        }
    }
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ANS[i])
            continue;

        timer++;
        bool a = check(i, 0, timer, 0);

        timer++;
        bool b = check(i, 1, timer, 0);
        
        timer++;
        if (a)
            check(i, 0, timer, 1);
        else
            check(i, 1, timer, 1);

        if (a && b)
            ans = ans * 2 % mod;
    }
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++)
    {
        if (ANS[i] == 1)
            printf("%d ", matching[i].f + 1);
        else
            printf("%d ", matching[i].s + 1);
    }
    printf("\n");
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}