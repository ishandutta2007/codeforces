#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 400001;

int col[maxn];
int rk[maxn];
set<int> merged;

int get(int u)
{
    if (col[u] == u)
        return u;
    return col[u] = get(col[u]);
}

void join(int u, int v)
{
    u = get(u), v = get(v);
    if (u == v)
        return;
    if (rk[u] > rk[v])
        swap(u, v);
    if (rk[u] == rk[v])
        ++rk[v];
    col[u] = v;
}

void join_all(int l, int r)
{
    while (true)
    {
        auto it = merged.lower_bound(l);
        if (it == merged.end() || *it >= r)
            return;
        join(*it, *it + 1);
        merged.erase(it);
    }
}

int solve()
{
    int n, q;
    cin >> n >> q;
    forn (i, n)
        col[i] = i;
    forn (i, n - 1)
        merged.insert(i);
    forn (i, q)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (t == 1)
            join(a - 1, b - 1);
        else if (t == 2)
            join_all(a - 1, b - 1);
        else
        {
            bool res = get(a - 1) == get(b - 1);
            cout << (res ? "YES\n" : "NO\n");
        }
    }
    return 0;
}