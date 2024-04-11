#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, q, a[3][N];
ll b[3][N], ans = -INF;

ll A[N], B[N], C[N], ANS[N];

int ql[N], qr[N], qk[N], qp[N];

ll get(int i, int l, int r)
{
    if (l == 0)
        return b[i][r];
    return b[i][r] - b[i][l - 1];
}

void solve1(int l, int r, vector<int> &v, ll kek = -INF)
{

    vector<int> vv;
    for (auto i : v)
    {
        int vl = ql[i];
        int vr = qr[i];
        if (vr < l || r < vl || vl > vr)
            continue;
        if (vl <= l && r <= vr)
            kek = max(kek, (ll)qk[i]);
        else
            vv.pb(i);
    }

    if (l == r)
    {
        ANS[l] = max(ANS[l], A[l] + kek);
        return;
    }

    int m = (l + r) >> 1;

    solve1(l, m, vv, kek);

    for (int i = l; i <= r; i++)
        C[i] = -INF;
    for (int i = m; i >= l; i--)
        C[i] = A[i];
    for (int i = m - 1; i >= l; i--)
        C[i] = max(C[i], C[i + 1]);

    for (auto i : vv)
    {
        if (ql[i] <= m && m < qr[i])
        {
            ll val = -INF;
            val = max(val, C[max(ql[i], l)]);
            C[min(qr[i], r)] = max(C[min(qr[i], r)], val + qk[i]);
        }
    }

    C[r] = max(C[r], C[l] + kek);
    for (int i = r - 1; i > m; i--)
        C[i] = max(C[i], C[i + 1]);
    for (int i = m + 1; i <= r; i++)
        ANS[i] = max(ANS[i], C[i]);
    solve1(m + 1, r, vv, kek);
}
void solve2(int l, int r, vector<int> &v, ll kek = -INF)
{

    vector<int> vv;
    for (auto i : v)
    {
        int vl = ql[i];
        int vr = qr[i];
        if (vr < l || r < vl || vl > vr)
            continue;
        if (vl <= l && r <= vr)
            kek = max(kek, (ll)qk[i]);
        else
            vv.pb(i);
    }

    if (l == r)
    {
        // ANS[l] = max(ANS[l], A[l] + kek);
        return;
    }

    int m = (l + r) >> 1;

    solve2(l, m, vv, kek);

    for (int i = l; i <= r; i++)
        C[i] = -INF;
    for (int i = m; i >= l; i--)
        C[i] = ANS[i];
    for (int i = m - 1; i >= l; i--)
        C[i] = max(C[i], C[i + 1]);

    for (auto i : vv)
    {
        if (ql[i] <= m && m < qr[i])
        {
            ll val = -INF;
            val = max(val, C[max(ql[i], l)]);
            C[min(qr[i], r)] = max(C[min(qr[i], r)], val + qk[i]);
        }
    }

    C[r] = max(C[r], C[l] + kek);
    for (int i = r - 1; i > m; i--)
        C[i] = max(C[i], C[i + 1]);
    for (int i = m + 1; i <= r; i++)
        ANS[i] = max(ANS[i], C[i]);
    solve2(m + 1, r, vv, kek);
}
void solve()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            b[i][j] = a[i][j];
        }
        for (int j = 1; j < n; j++)
            b[i][j] += b[i][j - 1];
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = get(0, 0, i) - get(1, 0, i - 1);
        B[i] = get(2, i, n - 1) + get(1, 0, i);
        ANS[i] = -INF;
    }

    vector<int> qv;
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &ql[i], &qr[i], &qk[i]);
        ql[i]--, qr[i]--;
        qk[i] = -qk[i];
        qv.pb(i);
    }

    solve1(0, n - 1, qv);
    for (int i = 0; i < q; i++)
        ql[i]--;

    solve2(0, n - 1, qv);

    for (int i = 0; i < n; i++)
        ans = max(ans, ANS[i] + B[i]);
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}