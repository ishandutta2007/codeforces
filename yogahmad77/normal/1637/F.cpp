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

int h[mx], p[mx], anak[mx];
vector<int> g[mx];

void dfs(int now, int par = 0)
{
    p[now] = par;
    for (int i : g[now])
    {
        if (i != par)
        {
            anak[now] += 1;
            dfs(i, now);
        }
    }
}

void solve(int tc)
{
    int n;
    cin >> n;
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        if (h[root] < h[i])
            root = i;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(root);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (anak[i] == 0)
            q.push(i);
    }

    long long ans = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == root)
        {
            if (sz(g[now]) == 1)
            {
                int gede = 0;
                for (int i : g[now])
                {
                    if (i == p[now])
                        continue;
                    gede = max(gede, h[i]);
                }

                ans += h[now] - gede;
                ans += h[now];
                continue;
            }
            else
            {
                int gede1 = 0, gede2 = 0;
                for (int i : g[now])
                {
                    if (i == p[now])
                        continue;
                    if (gede1 < h[i])
                    {
                        gede2 = gede1;
                        gede1 = h[i];
                    }
                    else if (gede2 < h[i])
                        gede2 = h[i];
                }
                ans += h[now] - gede1;
                ans += h[now] - gede2;
            }
            //
            break;
        }

        int gede = 0;
        for (int i : g[now])
        {
            if (i == p[now])
                continue;
            gede = max(gede, h[i]);
        }
        // debug(now, gede, h[now], anak[p[now]]);

        if (gede < h[now])
        {
            ans += h[now] - gede;
        }
        else
        {
            h[now] = gede;
        }

        anak[p[now]] -= 1;
        if (anak[p[now]] == 0)
            q.push(p[now]);
    }
    cout << ans << '\n';
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