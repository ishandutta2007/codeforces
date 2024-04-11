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

const int mx = 1e5 + 10;
const int MOD = 1e9 + 7;

int n;
vector<int> g[mx];

int l[mx], r[mx];
long long dp[mx][2];

long long f(int now, int atas, int par)
{
    long long &ret = dp[now][atas];
    if (ret != -1)
        return ret;

    ret = 0;
    long long sum = 0;
    if (par != 0)
    {
        if (atas == 0)
            sum = abs(l[now] - l[par]);
        else
            sum = abs(l[now] - r[par]);
    }
    for (int i : g[now])
    {
        if (i == par)
            continue;
        sum += f(i, 0, now);
    }
    ret = max(ret, sum);
    sum = 0;
    if (par != 0)
    {
        if (atas == 0)
            sum = abs(r[now] - l[par]);
        else
            sum = abs(r[now] - r[par]);
    }
    for (int i : g[now])
    {
        if (i == par)
            continue;
        sum += f(i, 1, now);
    }
    ret = max(ret, sum);
    return ret;
}

void solve(int tc)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = -1;
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << f(1, 0, 0) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    cin >> t;
    while (t--)
    {
        solve(++tc);
    }
}