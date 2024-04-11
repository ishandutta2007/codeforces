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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, pair<int, int>>> edge;
    int apa = -1;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w >= k)
        {
            if (apa == -1)
                apa = w;
            else
                apa = min(apa, w);
        }
        u -= 1;
        v -= 1;
        edge.push_back({w, {u, v}});
    }
    sort(ALL(edge));
    vector<int> par(n);
    iota(ALL(par), 0);
    function<int(int)> cari = [&](int u) {
        if (u == par[u])
            return u;
        return par[u] = cari(par[u]);
    };
    int maks = 0;
    long long total = 0;
    for (auto x : edge)
    {
        int u = x.s.f;
        int v = x.s.s;
        u = cari(u);
        v = cari(v);
        if (u == v)
            continue;
        par[u] = v;
        maks = max(maks, x.f);
        if (x.f >= k)
        {
            total += x.f - k;
        }
    }
    long long ans = 1e18;
    // debug(total, maks, apa);
    if (maks >= k)
        ans = total;
    else
    {
        ans = min(ans, total + k - maks);
        if (apa != -1)
            ans = min(ans, (long long)apa - k);

        iota(ALL(par), 0);
        reverse(ALL(edge));
        {
            int maks = 0;
            long long total = 0;
            for (auto x : edge)
            {
                if (x.f >= k)
                    continue;
                int u = x.s.f;
                int v = x.s.s;
                u = cari(u);
                v = cari(v);
                if (u == v)
                    continue;
                par[u] = v;
                maks = max(maks, x.f);
                if (x.f >= k)
                {
                    total += x.f - k;
                }
            }
            ans = min(ans, total + k - maks);
        }
    }
    cout << ans << '\n';
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