#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, q;
int qt[N], ql[N], qr[N], qx[N];
set<int> st;

int k, p[N];

int val[N], ans[N];

pair<pii, pii> t[N << 2];

pair<pii, pii> merge(pair<pii, pii> a, pair<pii, pii> b)
{
    vector<pii> c = {a.f, a.s, b.f, b.s};
    sort(c.begin(), c.end());
    return {c[3], c[2]};
}
void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = {{ans[tl], tl}, {0, 0}};
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

pair<pii, pii> get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l || l > r)
        return {{0, 0}, {0, 0}};
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return merge(
        get(v << 1, tl, tm, l, r),
        get(v << 1 | 1, tm + 1, tr, l, r));
}
void solve()
{
    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++)
        st.insert(i);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &qt[i]);
        if (qt[i] == 0)
        {
            scanf("%d%d%d", &ql[i], &qr[i], &qx[i]);
            if (qx[i] == 0)
            {
                while (true)
                {
                    auto it = st.lower_bound(ql[i]);
                    if (it == st.end() || *it > qr[i])
                        break;
                    val[*it] = 0;
                    ans[*it] = k + 1;
                    k++;
                    st.erase(it);
                }
            }
            else
            {
            }
        }
        else
        {
            scanf("%d", &qx[i]);
        }
    }

    while (!st.empty())
    {
        auto it = st.begin();
        val[*it] = 1;
        ans[*it] = inf;
        st.erase(it);
    }

    // for (int i = 1; i <= n; i++)
    //     cerr << val[i] << " ";
    // cerr << endl;
    // for (int i = 1; i <= n; i++)
    //     cerr << ans[i] << " ";
    // cerr << endl;

    build(1, 1, n);

    int cur = 0;
    for (int i = 0; i < q; i++)
    {
        if (qt[i] == 0)
        {
            pair<pii, pii> res = get(1, 1, n, ql[i], qr[i]);
            if (qx[i] == 0)
                cur = max(cur, res.f.f);
            else if (res.f.f == inf && res.s.f != inf)
                ans[res.f.s] = min(ans[res.f.s], res.s.f);
        }
        else
        {
            if (ans[qx[i]] > cur)
                printf("N/A\n");
            else if (val[qx[i]] == 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}