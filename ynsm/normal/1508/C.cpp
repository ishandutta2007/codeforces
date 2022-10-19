#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)4e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector<int> g[N];
int n, m;
int s[N], t[N], w[N], W;
bool was[N], used[N];
int p[N];
int pr[N];
bool in_mst[N];
ll MST;

set<pii> st[N];
int id[N];

bool cmp(int i, int j)
{
    return w[i] < w[j];
}
int get_pr(int v)
{
    if (v == pr[v])
        return v;
    return pr[v] = get_pr(pr[v]);
}

void dfs(int v, int pr)
{
    for (auto e : g[v])
    {
        if (!in_mst[e])
            continue;
        int to = v ^ s[e] ^ t[e];
        if (to == pr)
            continue;
        dfs(to, v);
        if (w[e] == 0 && !st[id[to]].empty())
            W = min(W, st[id[to]].begin()->f);

        if (st[id[v]].size() < st[id[to]].size())
            swap(id[v], id[to]);
        for (auto x : st[id[to]])
        {
            if (st[id[v]].find(x) == st[id[v]].end())
                st[id[v]].insert(x);
            else
                st[id[v]].erase(x);
        }
    }
}
int main()
{
    for (int i = 0; i < N; i++)
        id[i] = i, pr[i] = i;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &s[i], &t[i], &w[i]);
        s[i]--, t[i]--;
        g[s[i]].pb(i);
        g[t[i]].pb(i);
        W ^= w[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (was[i])
            continue;
        set<int> A, B;
        for (int j = 0; j < n; j++)
            if (i == j)
                A.insert(i);
            else
                B.insert(j);
        while (!A.empty())
        {
            int v = *A.begin();
            A.erase(v);
            was[v] = 1;
            for (auto e : g[v])
            {
                int to = v ^ s[e] ^ t[e];
                used[to] = 1;
            }

            set<int> C;
            for (auto x : B)
                if (!used[x])
                {
                    s[m] = v;
                    t[m] = x;
                    w[m] = 0;
                    g[s[m]].pb(m);
                    g[t[m]].pb(m);
                    m++;
                    A.insert(x);
                }
                else
                    C.insert(x);
            B = C;

            for (auto e : g[v])
            {
                int to = v ^ s[e] ^ t[e];
                used[to] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
        p[i] = i;
    sort(p, p + m, cmp);
    for (int i = 0; i < m; i++)
    {
        int e = p[i];
        int v = s[e];
        int u = t[e];

        v = get_pr(v);
        u = get_pr(u);
        if (v == u)
            in_mst[e] = 0;
        else
        {
            in_mst[e] = 1;
            MST += w[e];
            pr[v] = u;
        }
    }
    if (W == 0 || m < 1ll * n * (n - 1) / 2)
    {
        printf("%lld", MST);
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        if (in_mst[i])
            continue;
        int v = s[i];
        int u = t[i];
        st[id[v]].insert({w[i], i});
        st[id[u]].insert({w[i], i});
    }
    dfs(0, 0);
    printf("%lld", MST + W);
}