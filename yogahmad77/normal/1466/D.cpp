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

void solve(int tc)
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ve(n);
    iota(ALL(ve), 0);
    sort(ALL(ve), [&](int i, int j) {
        return w[i] > w[j];
    });
    int is_root = 1;
    long long ans = 0;
    vector<int> apa;
    for (int i : ve)
    {
        int berapa = sz(g[i]);
        if (is_root)
        {
            is_root = 0;
        }
        else
        {
            berapa -= 1;
            ans += w[i];
        }
        while (sz(apa) < n - 1 && berapa > 0)
        {
            berapa -= 1;
            apa.push_back(w[i]);
        }
    }
    for (auto i : apa)
    {
        ans += i;
        cout << ans << ' ';
    }
    cout << '\n';
    // debug(sz(apa));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}