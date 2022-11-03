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

const int mx = 1e6 + 10;

const int MOD = 1e9 + 7;

int p[mx];

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

int banyak_faktor(int x)
{
    if (x == 0)
        return 1;

    int ret = 1;
    while (x > 1)
    {
        int fak = p[x];
        int cnt = 1;
        while (x % fak == 0)
        {
            x /= fak;
            cnt += 1;
        }
        ret = ret * cnt;
    }
    return ret;
}

mint fak[mx];

void solve(int tc)
{
    int n;
    cin >> n;
    n *= 2;

    mint ans(0);

    for (int i = 2; i <= n; i += 2)
    {
        int ff = banyak_faktor(i / 2);
        int sisa = n - i;
        sisa /= 2;
        mint brp = mint(ff) * fak[sisa];
        ans += mint(ff) * fak[sisa];
    }

    cout << (ans.x) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < mx; i++)
    {
        if (p[i])
            continue;
        for (int j = i; j < mx; j += i)
        {
            if (p[j] == 0)
            {
                p[j] = i;
            }
        }
    }

    fak[0] = mint(1);
    mint sum(1);

    for (int i = 1; i < mx; i++)
    {
        fak[i] = sum;
        sum += fak[i];
    }
    int t = 1;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}