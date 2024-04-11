#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector<int> g[N], gr[N];
int n, m;
int s[N], t[N], w[N];
bool used[N], was[N];
int order[N], on;
int component[N], cn;
bool cur[N];

ll ans[N], G;
ll d[N];

int st[N];

int pr[N];
int pp(int v)
{
    return (pr[v] == v ? v : pr[v] = pp(pr[v]));
}
void dfs1(int v)
{
    used[v] = 1;
    for (auto i : g[v])
    {
        int to = s[i] ^ t[i] ^ v;
        if (used[to])
            continue;
        dfs1(to);
    }
    order[on++] = v;
}
void dfs2(int v)
{
    used[v] = 1;
    for (auto i : gr[v])
    {
        int to = s[i] ^ t[i] ^ v;
        if (used[to])
            continue;
        dfs2(to);
    }
    component[cn++] = v;
}
void dfs3(int v)
{
    // cerr << "D " << v << " " << d[v] << endl;
    pr[v] = v;
    was[v] = 1;
    for (auto i : g[v])
    {
        int to = s[i] ^ t[i] ^ v;
        if (!cur[to])
            continue;
        if (!was[to])
        {
            d[to] = d[v] + w[i];
            dfs3(to);
            pr[to] = v;
            continue;
        }
        int p = pp(to);

        // cerr << v << " " << to << " " << p << " " << (w[i] + d[v] - d[p]) << " " << (d[to] - d[p]) << endl;
        G = __gcd(G, abs((w[i] + d[v] - d[p]) - (d[to] - d[p])));
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &s[i], &t[i], &w[i]);
        s[i]--, t[i]--;
        g[s[i]].pb(i);
        gr[t[i]].pb(i);
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int v = order[i];
        if (used[v])
            continue;
        cn = 0;
        G = 0;
        dfs2(v);
        for (int j = 0; j < cn; j++)
            cur[component[j]] = 1;
        dfs3(v);
        for (int j = 0; j < cn; j++)
            cur[component[j]] = 0;
        // for (int j = 0; j < cn; j++)
        //     cerr << component[j] << " ";
        // cerr << G << endl;
        for (int j = 0; j < cn; j++)
            ans[component[j]] = G;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int v, s, t;
        scanf("%d%d%d", &v, &s, &t);
        v--;
        if (s % __gcd((ll)t, ans[v]) == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}