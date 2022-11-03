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

istream &operator>>(istream &is, mint &x)
{
    return is >> x.x;
}

ostream &operator<<(ostream &os, mint &x)
{
    return os << x.x;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<mint> banyak(60, mint(0));
    for (auto &i : a)
        cin >> i;
    for (auto i : a)
    {
        for (int j = 0; j < 60; j++)
        {
            if (i & (1LL << j))
            {
                banyak[j] += mint(1);
            }
        }
    }
    mint ans = mint(0);
    vector<mint> sum(n, mint(0));
    vector<mint> tot(n, mint(0));
    for (int i = 0; i < n; i++)
    {
        mint kali = mint(1);
        for (int bit = 0; bit < 60; bit++)
        {
            if (a[i] & (1LL << bit))
            {
                tot[i] += mint(n) * kali;
                sum[i] += banyak[bit] * kali;
            }
            else
            {
                tot[i] += banyak[bit] * kali;
            }
            kali *= mint(2);
        }
    }
    for (int j = 0; j < n; j++)
    {
        ans += tot[j] * sum[j];
    }
    cout << (ans.x) << '\n';
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