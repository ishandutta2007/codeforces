#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500;

const int mod = 998244353;

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

int n, m, a[N], b[N];

int ans;

int get(int l, int r)
{
    if (l > r)
        return 0;
    return b[r] - b[l - 1];
}
void solve(int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) >> 1;
    solve(l, m);
    solve(m + 1, r);

    // cerr << l << " " << r << " " << ans << endl;
    {

        vector<int> A(m - l + 1);
        vector<int> B(r - m);

        for (int i = l; i <= m; i++)
            A[i - l] = pw(2, get(1, i));
        for (int i = m + 1; i <= r; i++)
            B[i - m - 1] = pw(2, get(i, n));
        poly_mult(A, B);
        for (int i = 0; i < A.size(); i++)
        {
            int pos = i + l + m + 1;
            if (pos & 1)
                continue;
            pos >>= 1;
            ans = sum(ans, mult(a[pos], A[i]));
        }
    }
}
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        b[x] = 1;
    }
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    solve(1, n);
    // ans = mult(ans, inv(2));

    // cerr << ans << endl;
    // ans = 0;
    {
        int x = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                x = sum(x, a[i / 2]);
            ans = sum(ans, mult(x, sub(pw(2, get(i, n)), 1)));
        }
    }
    {
        int x = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if ((n - i + 1) % 2 == 0)
                x = sum(x, a[n - (n - i + 1) / 2 + 1]);
            ans = sum(ans, mult(x, sub(pw(2, get(1, i)), 1)));
        }
    }

    for (int i = 1; i <= n; i++)
        ans = sub(ans, mult(a[i], min(i - 1, n - i)));
    // cerr << ans << endl;

    ans = mult(ans, inv(sub(pw(2, m), 1)));
    printf("%d\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}