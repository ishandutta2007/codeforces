#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

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
    freopen("d.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1e6;
int a[maxn];
int pr[maxn];
int ql[maxn], qr[maxn];
int ans[maxn];
int coords[maxn];
int last[maxn];
vector <int> queries[maxn];

const int base = (1 << 19);
int t[base * 2];

void put(int v, int val)
{
    v += base;
    t[v] = min(t[v], val);
    while (v > 1)
    {
        v /= 2;
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return INF;
    int cc = (cl + cr) / 2;
    return min(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

int solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        coords[i] = a[i];
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", ql + i, qr + i);
        --ql[i], --qr[i];
        queries[qr[i]].push_back(i);
    }

    sort(coords, coords + n);
    int k = unique(coords, coords + n) - coords;
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(coords, coords + k, a[i]) - coords;
    for (int i = 0; i < k; ++i)
        last[i] = -1;
    for (int i = 0; i < base * 2; ++i)
        t[i] = INF;

    for (int i = 0; i < n; ++i)
    {
        int pr = last[a[i]];
        last[a[i]] = i;
        if (pr != -1)
            put(pr, i - pr);
        for (int q: queries[i])
        {
            int l = ql[q];
            ans[q] = get(l, i);
            if (ans[q] == INF)
                ans[q] = -1;
        }
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
    return 0;
}