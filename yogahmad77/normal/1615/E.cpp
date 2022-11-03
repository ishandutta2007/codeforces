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

vector<int> g[mx];

int depth[mx], in[mx], out[mx], idx, id[mx], maks[mx * 4], lazy[mx * 4];
int leaf[mx], p[mx];

void dfs(int now = 0, int par = -1, int lev = 1)
{
    p[now] = par;
    in[now] = ++idx;
    id[idx] = now;
    depth[now] = lev;
    for (int i : g[now])
    {
        if (i != par)
        {
            dfs(i, now, lev + 1);
        }
    }
    out[now] = idx;
    if (in[now] == out[now])
        leaf[now] = 1;
}

int apa[mx * 4];

void build(int idx, int l, int r)
{
    if (l == r)
    {
        maks[idx] = depth[id[l]] * leaf[id[l]];
        // debug(id[l], depth[id[l]], leaf[id[l]]);
        apa[idx] = id[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    maks[idx] = max(maks[idx * 2], maks[idx * 2 + 1]);
    if (maks[idx] == maks[idx * 2])
        apa[idx] = apa[idx * 2];
    else
        apa[idx] = apa[idx * 2 + 1];
}

void upd(int idx, int l, int r, int fl, int fr)
{
    if (fl > r || fr < l)
        return;
    if (fl <= l && r <= fr)
    {
        maks[idx] -= 1;
        lazy[idx] -= 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (lazy[idx])
    {
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
        maks[idx * 2] += lazy[idx];
        maks[idx * 2 + 1] += lazy[idx];
        lazy[idx] = 0;
    }
    upd(2 * idx, l, mid, fl, fr);
    upd(2 * idx + 1, mid + 1, r, fl, fr);
    maks[idx] = max(maks[idx * 2], maks[idx * 2 + 1]);
    if (maks[idx] == maks[idx * 2])
        apa[idx] = apa[idx * 2];
    else
        apa[idx] = apa[idx * 2 + 1];
}

int sudah[mx];

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    dfs();
    build(1, 1, n);
    int red = 0;
    while (k > 0)
    {
        int aa = maks[1];
        int bb = apa[1];
        // debug(aa, bb);
        if (aa <= 0)
            break;
        red += 1;
        k -= 1;
        // debug(red, bb);
        int now = bb;
        while (now != -1 && !sudah[now])
        {
            sudah[now] = 1;
            upd(1, 1, n, in[now], out[now]);
            now = p[now];
        }
    }
    if (k > 0)
    {
        long long ans = 0;
        for (int i = 0; i <= k; i++)
        {
            // debug(red + i, n - red - i);
            ans = max(ans, 1LL * (red + i) * (n - red - i));
        }
        cout << ans << '\n';
        return;
    }
    int blue = 0;
    int white = n - red;
    long long ans = 1LL * white * (red - blue);
    for (int i = 0; i < n; i++)
    {
        if (!sudah[i])
        {
            // debug(white, red, blue);
            blue += 1;
            white -= 1;
            ans = min(ans, 1LL * white * (red - blue));
        }
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