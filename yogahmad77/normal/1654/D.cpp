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

struct mint
{
    const int MOD = 998244353;

    int x;

    mint(int _x) : x(_x) {}

    mint() : x(1) {}

    mint &operator=(const mint &rhs)
    {
        x = rhs.x;
        return *this;
    }

    mint pow(long long n) const
    {
        assert(0 <= n);
        mint x = *this, r = mint(1);
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const
    {
        return pow(MOD - 2);
    }

    mint &operator+=(const mint &rhs)
    {
        x += rhs.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint &rhs)
    {
        x -= rhs.x;
        if (x < 0)
            x += MOD;
        return *this;
    }
    mint &operator*=(const mint &rhs)
    {
        unsigned long long z = x;
        z *= rhs.x;
        x = (unsigned int)(z % MOD);
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

    friend mint operator+(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint &lhs, const mint &rhs)
    {
        return mint(lhs) /= rhs;
    }
};

vector<int> g[mx];
map<pair<int, int>, pair<int, int> > rat;
int in[mx], out[mx], idx, par[mx];
vector<pair<pair<int, int>, int> > isi[mx];
int p[mx];
void dfs(int now, int pp)
{
    in[now] = ++idx;
    par[now] = pp;
    for (int i : g[now])
    {
        if (i == pp)
            continue;
        dfs(i, now);
    }
    out[now] = idx;
}

void gen(int x, int u, int v)
{
    while (x > 1)
    {
        int fak = p[x];
        int cnt = 0;
        while (x % fak == 0)
        {
            x /= fak;
            cnt += 1;
        }
        isi[fak].push_back({{u, v}, cnt});
    }
}

mint sum[mx * 4], kali[mx * 4];
void build(int idx, int l, int r)
{
    kali[idx] = mint(1);
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
}

void upd1(int idx, int l, int r, int fl, int fr, mint val)
{
    if (fl > r || fr < l)
    {
        return;
    }
    if (fl <= l && r <= fr)
    {
        kali[idx] *= val;
        return;
    }
    int mid = (l + r) >> 1;
    upd1(2 * idx, l, mid, fl, fr, val);
    upd1(2 * idx + 1, mid + 1, r, fl, fr, val);
}

mint eval(int idx, int l, int r, mint aa)
{
    if (l == r)
    {
        // debug(aa.x, kali[idx].x);
        return aa * kali[idx];
    }
    int mid = (l + r) >> 1;
    return eval(2 * idx, l, mid, aa * kali[idx]) +
           eval(2 * idx + 1, mid + 1, r, aa * kali[idx]);
}

int mini[mx * 4], lazy[mx * 4];

void upd2(int idx, int l, int r, int fl, int fr, int val)
{
    if (fl > r || fr < l)
    {
        return;
    }
    if (fl <= l && r <= fr)
    {
        mini[idx] += val;
        lazy[idx] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if (lazy[idx] != 0)
    {
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
        mini[idx * 2] += lazy[idx];
        mini[idx * 2 + 1] += lazy[idx];
        lazy[idx] = 0;
    }
    upd2(2 * idx, l, mid, fl, fr, val);
    upd2(2 * idx + 1, mid + 1, r, fl, fr, val);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}

void upd(int l, int r, int v, int n, int prima)
{
    if (prima > 0)
    {
        // debug(l, r, prima, v);
        upd1(1, 1, n, l, r, mint(prima).pow(v));
    }
    // for (; l <= n; l += l & -l)
    //     bit[l] += v;
    // r += 1;
    // for (; r <= n; r += r & -r)
    //     bit[r] -= v;

    upd2(1, 1, n, l, r, v);
}
int berapa[mx];
void solve(int tc)
{
    idx = 0;
    int n;
    cin >> n;
    rat.clear();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        isi[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v, w, x;
        cin >> u >> v >> w >> x;
        int fpb = __gcd(w, x);
        w /= fpb;
        x /= fpb;
        g[u].push_back(v);
        g[v].push_back(u);
        gen(w, u, v);
        gen(x, v, u);
    }
    dfs(1, 0);
    build(1, 1, n);
    for (int i = 2; i <= n; i++)
    {
        if (p[i] != i)
            continue;
        vector<tuple<int, int, int> > hapus;
        for (pair<pair<int, int>, int> x : isi[i])
        {
            int u = x.first.first;
            int v = x.first.second;
            int w = x.second;
            long long tambah = 0;
            // if (w > now)
            // tambah = w - now;
            tambah = w;
            // if (w > berapa[u])
            // {
            //     tambah = w - berapa[u];
            //     berapa[u] = w;
            // }
            // debug(u, v, w, tambah);
            if (tambah == 0)
                continue;
            if (u == par[v])
            {
                upd(1, in[v] - 1, tambah, n, i);
                hapus.push_back(make_tuple(1, in[v] - 1, -tambah));
                upd(out[v] + 1, n, tambah, n, i);
                hapus.push_back(make_tuple(out[v] + 1, n, -tambah));
            }
            else
            {
                upd(in[u], out[u], tambah, n, i);
                hapus.push_back(make_tuple(in[u], out[u], -tambah));
            }
        }
        int mi = mini[1];
        upd1(1, 1, n, 1, n, mint(1) / mint(i).pow(mi));
        // auto brp = eval(1, 1, n, mint(1)).x;
        // debug(i, brp);

        for (auto x : hapus)
        {
            int a, b, c;
            tie(a, b, c) = x;
            upd(a, b, c, n, -1);
        }
        for (auto x : isi[i])
            berapa[x.f.f] = 0;
    }
    auto ans = eval(1, 1, n, mint(1));
    cout << (ans.x) << '\n';
}

int main()
{
    p[1] = 1;
    for (int i = 2; i < mx; i++)
    {
        if (p[i])
            continue;
        for (int j = i; j < mx; j += i)
            p[j] = i;
    }
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