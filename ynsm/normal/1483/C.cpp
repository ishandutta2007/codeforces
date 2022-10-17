#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], b[N], s[N], t[N];
stack<int> st;
ll dp[N];
ll T[N << 2], u[N << 2];

void upd(int v, int tl, int tr, int l, int r, ll x)
{
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r)
    {
        u[v] += x;
        T[v] += x;  
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(v << 1, tl, tm, l, r, x);
    upd(v << 1 | 1, tm + 1, tr, l, r, x);
    T[v] = max(T[v << 1], T[v << 1 | 1]) + u[v];
}
ll get(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l)
        return -INF;
    if (l <= tl && tr <= r)
        return T[v];
    int tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r)) + u[v];
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            int j = st.top();
            upd(1, 0, n, s[j], t[j], -b[j]);
            s[j] = t[j] = -1;
            st.pop();
        }
        if (st.empty())
        {
            s[i] = 0;
            t[i] = n;
            upd(1, 0, n, s[i], t[i], b[i]);
        }
        else
        {
            int j = st.top();
            upd(1, 0, n, s[j], t[j], -b[j]);
            t[j] = j - 1;
            upd(1, 0, n, s[j], t[j], b[j]);

            s[i] = j;
            t[i] = n;
            upd(1, 0, n, s[i], t[i], b[i]);
        }
        st.push(i);

        dp[i] = get(1, 0, n, 0, i - 1);
        upd(1, 0, n, i, i, dp[i]);
        // cerr << i << " " << dp[i] << endl;
        // for (int j = 1; j <= n; j++)
        //     cerr << s[j] << " " << t[j] << endl;
        // cerr << endl;
    }
    printf("%lld", dp[n]);
}