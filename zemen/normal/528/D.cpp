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

const int maxn = 210001;

char s[maxn], t[maxn];
int conv[1000];

const int mod = 7340033;
const int eps = 2187;
const int maxdeg = 20;

int epow[2][maxdeg + 1];

int mul(ll a, ll b)
{
    return (a * b) % mod;
}

int rev(int a)
{
    int deg = mod - 2;
    int res = 1;
    while (deg)
    {
        if (deg & 1)
            res = mul(res, a);
        deg >>= 1;
        a = mul(a, a);
    }
    return res;
}

int bitrev(int a, int deg)
{
    int res = 0;
    for (int i = 0; i < deg; ++i)
        res |= ((a >> i) & 1) << (deg - 1 - i);
    return res;
}

int sum(int a, int b)
{
    return (a + b) % mod;
}

int sub(int a, int b)
{
    return (a - b + mod) % mod;
}

void fft(vector <int> &a, bool invert)
{
    int n = sz(a);
    int deg = 0;
    while ((1 << deg) < n)
        ++deg;
    assert((1 << deg) == n);
    for (int i = 0; i < n; ++i)
    {
        int r = bitrev(i, deg);
        if (r < i)
            swap(a[i], a[r]);
    }
    for (int d = 1; d <= deg; ++d)
    {
        int len = (1 << d);
        for (int s = 0; s < n; s += len)
        {
            int e = epow[invert][d];
            int ek = 1;
            for (int i = 0; i < len / 2; ++i)
            {
                int w0 = a[s + i];
                int w1 = a[s + len / 2 + i];
                a[s + i] = sum(w0, mul(ek, w1));
                a[s + len / 2 + i] = sub(w0, mul(ek, w1));
                ek = mul(ek, e);
            }
        }
    }
    if (invert)
    {
        int rn = rev(n);
        for (int i = 0; i < n; ++i)
            a[i] = mul(a[i], rn);
    }
}

vector <int> mul(vector <int> a, vector <int> b)
{
//    vector <int> res(sz(a) + sz(b), 0);
//    for (int i = 0; i < sz(a); ++i)
//        for (int j = 0; j < sz(b); ++j)
//            res[i + j] += a[i] * b[j];
//    return res;
    int n = 1;
    while (n < sz(a) + sz(b))
        n *= 2;
    a.resize(n);
    b.resize(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; ++i)
        a[i] = mul(a[i], b[i]);
    fft(a, true);
    return a;
}

vector <int> p, r;
vector <int> res;
int cnt[maxn];

int solve()
{
    epow[0][maxdeg] = eps;
    epow[1][maxdeg] = rev(eps);
    for (int i = maxdeg - 1; i >= 0; --i)
    {
        epow[0][i] = mul(epow[0][i + 1], epow[0][i + 1]);
        epow[1][i] = mul(epow[1][i + 1], epow[1][i + 1]);
    }
//    cerr << epow[0][0] << ' ' << epow[0][1] << '\n';
    conv[int('A')] = 0;
    conv[int('T')] = 1;
    conv[int('G')] = 2;
    conv[int('C')] = 3;
    int n, m, k;
    cin >> n >> m >> k;
    scanf("%s%s", s, t);

    reverse(t, t + m);
    for (int q = 0; q < 4; ++q)
    {
        int rb = 0;
        p.clear();
        p.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (conv[int(s[i])] != q)
                continue;
            for (int j = max(rb, i - k); j < min(n, i + k + 1); ++j)
                p[j] = 1;
            rb = i + k + 1;
        }
//        for (int i = 0; i < n; ++i)
//            cerr << p[i];
//        cerr << '\n';
        r.clear();
        r.resize(m, 0);
        for (int i = 0; i < m; ++i)
            if (conv[int(t[i])] == q)
                r[i] = 1;
        res = mul(p, r);
        for (int i = 0; i + m <= n; ++i)
            cnt[i] += res[i + m - 1];
    }
    int ans = 0;
    for (int i = 0; i + m <= n; ++i)
        ans += (cnt[i] == m);
    cout << ans << '\n';
    return 0;
}