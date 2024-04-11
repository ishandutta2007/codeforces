#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector<int> ans;
set<pii> g[N];
int n, m, k, p[N];
ll a[N];
int pp(int v)
{
    return (p[v] == v ? v : p[v] = pp(p[v]));
}
int main()
{
    for (int i = 0; i < N; i++)
        p[i] = i;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        g[v].insert({u, i});
        g[u].insert({v, i});
    }
    set<pll> st;
    for (int i = 0; i < n; i++)
        st.insert({-a[i], i});
    while (st.size() > 1)
    {
        int v = st.begin()->s;
        st.erase(st.begin());
        while (!g[v].empty())
        {
            int u = g[v].begin()->f;
            int id = g[v].begin()->s;
            u = pp(u);
            if (v == u)
            {
                g[v].erase(g[v].begin());
                continue;
            }
            if (a[v] + a[u] >= k)
            {
                ans.pb(id);
                a[v] = a[v] + a[u] - k;
                p[u] = v;
                st.erase({-a[u], u});
                if (g[v].size() < g[u].size())
                    swap(g[v], g[u]);
                for (auto e : g[u])
                    g[v].insert(e);
                g[u].clear();
                break;
            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
        st.insert({-a[v], v});
    }
    printf("YES\n");
    for (auto e : ans)
        printf("%d\n", e + 1);
}