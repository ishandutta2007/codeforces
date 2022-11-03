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

const int mx = 2e5 + 10;
const int MOD = 1e9 + 7;

set<int> g[mx];

int is_non_vulnerable(int i)
{
    if (g[i].empty())
        return 1;
    else
    {
        int x = *prev(g[i].end());
        if (x < i)
        {
            return 1;
        }
    }

    return 0;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    int non_vul = 0;
    for (int i = 0; i < n; i++)
    {
        non_vul += is_non_vulnerable(i);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int t, u, v;
        cin >> t;
        if (t == 3)
        {
            cout << non_vul << '\n';
            continue;
        }
        cin >> u >> v;
        u--;
        v--;
        non_vul -= is_non_vulnerable(u);
        non_vul -= is_non_vulnerable(v);
        if (t == 1)
        {
            g[u].insert(v);
            g[v].insert(u);
        }
        else
        {
            g[u].erase(v);
            g[v].erase(u);
        }
        non_vul += is_non_vulnerable(u);
        non_vul += is_non_vulnerable(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}