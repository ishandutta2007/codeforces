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

    mint() : x(0) {}

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

mint bit[mx];

void upd(int l, int r, mint val)
{
    for (; l < mx; l += l & -l)
        bit[l] += val;

    r += 1;
    for (; r < mx; r += r & -r)
        bit[r] -= val;
}

mint get(int l)
{
    mint ret(0);
    for (; l > 0; l -= l & -l)
        ret += bit[l];
    return ret;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), t(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> t[i];
    }

    upd(1, n, 1);

    mint ans(0);

    for (int i = n - 1; i >= 0; i--)
    {
        mint berapa = get(i + 1) + t[i];
        mint sum = berapa * 2 - 2;
        mint tambah = sum / 2;
        // debug(i, tambah.x);
        ans += tambah * mint(x[i] - y[i]);
        int in = lower_bound(ALL(x), y[i]) - x.begin();
        upd(in + 1, i, tambah);
    }

    ans += mint(x[n - 1] + 1);

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