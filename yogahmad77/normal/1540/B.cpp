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

const int mx = 200 + 10;
const int MOD = 1e9 + 7;

vector<int> g[mx];
int p[mx], level[mx];
void dfs(int now, int par, int lev = 0)
{
    p[now] = par;
    level[now] = lev;
    for (int i : g[now])
    {
        if (i != par)
        {
            dfs(i, now, lev + 1);
        }
    }
}

struct mint
{
    const int MOD = 1e9 + 7;

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

mint f[mx][mx];
int sudah[mx][mx];

mint dua(500000004);

// kiri duluan
mint dp(int kiri, int kanan)
{
    if (kiri == 0)
        return 1;

    if (kanan == 0)
        return 0;

    mint &ret = f[kiri][kanan];
    if (sudah[kiri][kanan])
        return ret;

    sudah[kiri][kanan] = true;

    ret = mint(0);

    // kiri
    ret += dp(kiri - 1, kanan) * dua;
    // kanan
    ret += dp(kiri, kanan - 1) * dua;

    return ret;
}

int lca(int x, int y)
{
    if (x == y)
        return x;
    if (level[x] > level[y])
        return lca(p[x], y);

    if (level[x] < level[y])
        return lca(x, p[y]);

    return lca(p[x], p[y]);
}

void solve(int tc)
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mint ans(0);
    for (int root = 1; root <= n; root++)
    {
        dfs(root, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int pp = lca(i, j);
                int kiri = level[j] - level[pp];
                int kanan = level[i] - level[pp];
                ans += dp(kiri, kanan);

                // debug(root, i, j, dp(kiri, kanan).x);
            }
        }
    }

    ans /= mint(n);

    cout << (ans.x) << '\n';
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