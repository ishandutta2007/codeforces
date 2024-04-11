#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) { return (1LL * a * b) % mod; }

int pw(int a, int b)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int inv(int x) { return pw(x, mod - 2); }

int sub(int a, int b)
{
    int s = a - b;
    if (s < 0)
        s += mod;
    return s;
}

int sum(int a, int b)
{
    int s = a + b;
    if (s >= mod)
        s -= mod;
    return s;
}

void fft(vector<int> &a, bool invert)
{
    int n = (int)a.size();

    for (int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = int(wlen * 1ll * wlen % mod);
        for (int i = 0; i < n; i += len)
        {
            int w = 1;
            for (int j = 0; j < len / 2; ++j)
            {
                int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = int(w * 1ll * wlen % mod);
            }
        }
    }
    if (invert)
    {
        int nrev = pw(n, mod - 2);
        for (int i = 0; i < n; ++i)
            a[i] = int(a[i] * 1ll * nrev % mod);
    }
}

void poly_mult(vector<int> &a, vector<int> b)
{
    int s = a.size() + b.size();
    int r = 1;
    while (r < s)
        r *= 2;
    a.resize(r);
    b.resize(r);
    fft(a, false);
    fft(b, false);
    for (int j = 0; j < r; j++)
    {
        a[j] = mult(a[j], b[j]);
    }
    fft(a, true);
    int x;

    while (a.size() >= s)
        a.pop_back();
}

int n, ans[N];

int fact[N], invfact[N];

int bp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}

int CC(int n, int k, int p)
{
    int res = 0;
    // cerr << n << " " << k << " " << p <<    endl;
    res = sum(res, C(n + p + 1, k + 1));
    // res = sub(res, C(n + 1, k + 1));
    // for (int i = 0; i <= p; i++)
    //     res = sum(res, C(n + i, k));
    return res;
}
int CC(int n, int k, int pl, int pr)
{
    if (pl > pr)
        return 0;
    if (pl == 0)
        return CC(n, k, pr);
    return sub(CC(n, k, pr), CC(n, k, pl - 1));
}
void solve()
{
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        ans[i] = CC(i - 1, i - 1, max(0, n / 2 - i + 1), n - i - 1);
        ans[i] = mult(ans[i], fact[n - i - 1]);
        ans[i] = mult(ans[i], fact[i]);
    }

    vector<int> a, b;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = invfact[i];

        if (i > n / 2)
        {
            int x = 1;
            x = mult(x, invfact[i]);
            x = mult(x, fact[i - 1]);
            x = mult(x, fact[n - i - 1]);
            b[i] = x;
        }
    }
    poly_mult(a, b);

    for (int i = 1; i < n; i++)
    {
        int cur = 0;
        // for (int j = 0; j <= n - i - 1; j++)
        // {
        //     if (j > n / 2)
        //     {
        //         int x = 1;

        //         x = mult(x, invfact[n - i - j - 1]);

        //         x = mult(x, invfact[j]);
        //         x = mult(x, fact[j - 1]);
        //         x = mult(x, fact[n - j - 1]);

        //         cur = sum(cur, x);
        //     }
        // }
        cur = a[n - i - 1];
        cur = mult(cur, fact[n - i - 1]);

        ans[i] = sum(ans[i], cur);
    }

    for (int i = 0; i < n; i++)
        ans[i] = sub(fact[n - 1], ans[i]);

    ans[0] = ans[1];
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
int main()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mult(fact[i - 1], i);
    for (int i = 0; i < N; i++)
        invfact[i] = bp(fact[i], mod - 2);

    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}