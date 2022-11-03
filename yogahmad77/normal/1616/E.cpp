#include <bits/stdc++.h>
using namespace std;
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
const int MOD = 1e9 + 7;

int mini[mx * 4];
int sum[mx * 4];
int n;
string s, t;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        mini[idx] = s[l - 1];
        sum[idx] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
    sum[idx] = (sum[idx * 2] + sum[idx * 2 + 1]);
}

int cari(int idx, int l, int r, int val)
{
    if (mini[idx] >= val)
        return n + 1;
    int mid = (l + r) >> 1;
    if (l == r)
        return l;
    if (mini[idx * 2] >= val)
        return cari(idx * 2 + 1, mid + 1, r, val);
    return cari(idx * 2, l, mid, val);
}

int jumlah(int idx, int l, int r, int fl, int fr)
{
    if (fl > r || fr < l)
        return 0;
    if (fl <= l && r <= fr)
        return sum[idx];
    int mid = (l + r) >> 1;
    auto aa = jumlah(2 * idx, l, mid, fl, fr);
    auto bb = jumlah(2 * idx + 1, mid + 1, r, fl, fr);
    return aa + bb;
}

void upd(int idx, int l, int r, int x)
{
    if (x > r || x < l)
        return;
    if (l == r)
    {
        sum[idx] = 0;
        mini[idx] = 1e9;
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * idx, l, mid, x);
    upd(2 * idx + 1, mid + 1, r, x);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
    sum[idx] = (sum[idx * 2] + sum[idx * 2 + 1]);
}

int dp[mx];

void solve(int tc)
{
    cin >> n >> s >> t;
    long long tot = 0;
    long long ans = 1e18;
    build(1, 1, n);
    for (int i = 0; i < n; i++)
    {
        // cari yang lebih kecil terdekat
        int aa = cari(1, 1, n, t[i]);
        // debug(i, aa);
        if (aa != n + 1)
        {
            ans = min(ans, tot + jumlah(1, 1, n, 1, aa - 1));
        }
        // cari yang lebih kecil sama dengan terdekat
        aa = cari(1, 1, n, t[i] + 1);
        if (aa == n + 1)
            break;
        tot += jumlah(1, 1, n, 1, aa - 1);
        upd(1, 1, n, aa);
    }
    if (ans == 1e18)
        ans = -1;
    cout << ans << '\n';
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