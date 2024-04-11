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

mint prob[mx], pang[mx], inv[mx];

void solve(int tc)
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    vector<mint> ans(n + 1), kiri(n + 1);
    mint sumKiri(0);
    int l = n;
    for (int i = n; i >= 1; i--)
    {
        int satu = (i - 1) / 2;
        ans[i] = inv[satu];
        if (i == n)
        {
            kiri[i] = ans[i];
            continue;
        }
        while (l > 0 && l - (l - 1) / 2 > i)
        {
            // debug(l);
            sumKiri += ans[l];
            l--;
        }
        ans[i] = ans[i] * inv[1];
        kiri[i] = ans[i];
        // debug(i, sumKiri.x);
        ans[i] = ans[i] * (mint(1) - sumKiri);

        // int lo = 0, hi = n - i - 1, mid, di = -1; // minimal berapa urut biar kalah
        // while (lo <= hi)
        // {
        //     mid = (lo + hi) / 2;
        //     int kiri = i + (n - i - 1) - mid;
        //     int kanan = mid + 1;
        //     if (kanan >= kiri)
        //     {
        //         hi = mid - 1;
        //         di = mid;
        //     }
        //     else
        //         lo = mid + 1;
        // }
        // if (di != -1)
        // {
        //     if (i == 2)
        //     {
        //         // debug(ans[i].x, inv[di].x);
        //     }
        //     ans[i] = ans[i] * (mint(1) - inv[di]);
        // }
    }
    cout << 0 << '\n';
    for (int i = 2; i <= n; i++)
        cout << ans[i].x << '\n';
}

int main()
{
    mint bagi = mint(1) / mint(2);
    pang[0] = mint(1);
    inv[0] = mint(1);
    for (int i = 1; i < mx; i++)
    {
        pang[i] = pang[i - 1] * mint(2);
        inv[i] = inv[i - 1] * bagi;
    }
    int t = 1;
    cin >> t;
    int tc = 0;
    while (t--)
    {
        solve(++tc);
    }
}