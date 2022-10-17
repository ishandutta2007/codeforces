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

int n;
char s[N], t[N];

int t_cnt[N << 2], t_mask[N << 2];

int CNT = 0;

void upd(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        if (val >= 0)
        {
            t_mask[v] = (1 << val);
            t_cnt[v] = 1;
        }
        else
        {
            t_mask[v] = 0;
            t_cnt[v] = 0;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        upd(v << 1, tl, tm, pos, val);
    else
        upd(v << 1 | 1, tm + 1, tr, pos, val);
    t_cnt[v] = t_cnt[v << 1] + t_cnt[v << 1 | 1];
    t_mask[v] = t_mask[v << 1] | t_mask[v << 1 | 1];
}

int get(int v, int tl, int tr, int mask)
{
    if ((t_mask[v] & mask) == 0)
    {
        CNT += t_cnt[v];
        return -1;
    }
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    int res = -1;
    if (res == -1)
        res = get(v << 1, tl, tm, mask);
    if (res == -1)
        res = get(v << 1 | 1, tm + 1, tr, mask);
    return res;
}
void solve()
{
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; i < n; i++)
        s[i] -= 'a', t[i] -= 'a';
    for (int i = 0; i < n; i++)
        upd(1, 0, n - 1, i, s[i]);
    ll ans = INF, cur = 0;
    for (int i = 0; i < n; i++)
    {
        {
            CNT = 0;
            int x = get(1, 0, n - 1, (1 << t[i]) - 1);
            if (x != -1)
                ans = min(ans, cur + CNT);
        }
        CNT = 0;
        int x = get(1, 0, n - 1, (1 << t[i]));
        if (x == -1)
            break;
        upd(1, 0, n - 1, x, -1);
        cur += CNT;
    }
    if (ans == INF)
        ans = -1;
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}