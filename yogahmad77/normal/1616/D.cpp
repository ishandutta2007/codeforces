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
const int MOD = 1e9 + 7;

long long pref[mx], a[mx];
long long x;
long long mini[mx * 4];
int n;
int b[mx];

void build(int idx, int l, int r)
{
    if (l == r)
    {
        mini[idx] = pref[l] - x * l;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
}

long long cari(int idx, int l, int r, int fl, int fr)
{
    if (fl > r || fr < l)
        return 1e18;
    if (fl <= l && r <= fr)
        return mini[idx];
    int mid = (l + r) >> 1;
    auto aa = cari(2 * idx, l, mid, fl, fr);
    auto bb = cari(2 * idx + 1, mid + 1, r, fl, fr);
    return min(aa, bb);
}

int cari2(int idx, int l, int r, int x, long long val)
{
    if (mini[idx] >= val)
        return n + 1;
    if (r < x)
        return n + 1;
    int mid = (l + r) >> 1;
    if (x <= l)
    {
        if (l == r)
            return l;
        if (mini[idx * 2] >= val)
            return cari2(idx * 2 + 1, mid + 1, r, x, val);
        return cari2(idx * 2, l, mid, x, val);
    }
    int aa = cari2(idx * 2, l, mid, x, val);
    if (aa != n + 1)
        return aa;
    return cari2(idx * 2 + 1, mid + 1, r, x, val);
}

int cariKecil(int i)
{
    long long val = pref[i - 1] - x * (i - 1);
    return cari2(1, 1, n, i + 1, val);
    // int lo = i + 1, hi = n, ans = n + 1, mid;
    // while (lo <= hi)
    // {
    //     mid = (lo + hi) >> 1;
    //     auto aa = cari(1, 1, n, i + 1, mid);
    //     if (aa < val)
    //     {
    //         ans = mid;
    //         hi = mid - 1;
    //     }
    //     else
    //         lo = mid + 1;
    // }
    // return ans;
}

int dp[mx];

void solve(int tc)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    cin >> x;
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
        b[i] = cariKecil(i);
    for (int i = n - 1; i > 0; i--)
    {
        b[i] = min(b[i], b[i + 1]);
    }
    dp[n + 1] = 0;
    dp[n + 2] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({n + 1, n + 1});
    pq.push({n + 2, n + 2});
    for (int i = n; i > 0; i--)
    {
        int &ret = dp[i];
        ret = 0;
        while (!pq.empty())
        {
            if (pq.top().s > b[i] + 1)
            {
                pq.pop();
                continue;
            }
            break;
        }
        ret = pq.top().f - i - 1;
        // debug(i, ret, b[i], pq.top().s);
        pq.push({ret + i, i});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
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