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

vector<int> g[N];
int n, m, col[N];
set<int> st;

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        col[i] = 0;
    }
    st.clear();
    for (int i = 1; i <= m; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        g[v].pb(u);
        g[u].pb(v);
    }

    st.insert(1);
    while (!st.empty())
    {
        int v = *st.begin();

        queue<int> q2, q3;

        {
            col[v] = 1;
            st.erase(v);
            for (auto to : g[v])
            {
                if (col[to] != 2)
                {
                    col[to] = 2;
                    q2.push(to);
                }
            }
        }

        while (!q2.empty())
        {
            int u = q2.front();
            st.erase(u);
            q2.pop();
            for (auto to : g[u])
            {
                if (col[to] == 0)
                {
                    col[to] = 3;
                    q3.push(to);
                }
            }
        }

        while (!q3.empty())
        {
            int u = q3.front();
            st.insert(u);
            q3.pop();
        }
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            printf("NO\n");
            return;
        }
        if (col[i] == 1)
            k++;
    }
    printf("YES\n");
    printf("%d\n", k);
    for (int i = 1; i <= n; i++)
        if (col[i] == 1)
            printf("%d ", i);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}