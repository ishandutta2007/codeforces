#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t)
{
    cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v)
{
    cout << t;
    if (sizeof...(v))
        cout << ", ";
    cetak(v...);
}

#define debug(x...)               \
    cout << '(' << #x << ") = ("; \
    cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);

const int mx = 500 + 10;
vector<int> g[mx];
int suf[mx], pre[mx], dist[mx][mx];

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        pre[i] = -1;
        suf[i] = -1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = 1e9;
        }
    }
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back(make_tuple(u, v, w));
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    suf[n] = 0;
    pre[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i : g[now])
        {
            if (pre[i] == -1)
            {
                pre[i] = pre[now] + 1;
                q.push(i);
            }
        }
    }
    q.push(n);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i : g[now])
        {
            if (suf[i] == -1)
            {
                suf[i] = suf[now] + 1;
                q.push(i);
            }
        }
    }
    long long ans = 1e18;
    for (auto i : edge)
    {
        int u, v, w;
        tie(u, v, w) = i;
        ans = min(ans, 1LL * (pre[u] + suf[v] + 1) * w);
        ans = min(ans, 1LL * (pre[v] + suf[u] + 1) * w);
    }
    for (auto i : edge)
    {
        int u, v, w;
        tie(u, v, w) = i;
        for (int x = 1; x <= n; x++)
        {
            int pindah = min(dist[x][u], dist[x][v]) + 1;
            pindah += dist[x][1];
            pindah += dist[x][n];
            pindah += 1;
            ans = min(ans, 1LL * pindah * w);
        }
    }
    cout << ans << '\n';
}

int main()
{
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}