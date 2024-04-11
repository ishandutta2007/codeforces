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

int n, k, cnt[N], a[N];

void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    for (int i = 1; i <= n; i++)

    {
        int x;
        scanf("%d", &x);
        a[i] = x;
        cnt[x]++;
    }
    pair<int, pii> ans = {inf, {-1, -1}};
    for (int i = 1, j = 1, cur = 0; i <= n; i++)
    {
        while (j <= n && 2 * cur < n + k)
            cur += cnt[j++];
        if (2 * cur >= n + k)
            ans = min(ans, {j - i, {i, j}});
        cur -= cnt[i];
    }
    int l = ans.s.f;
    int r = ans.s.s - 1;

    printf("%d %d\n", l, r);

    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        a[i] = (l <= a[i] && a[i] <= r);
        if (st.empty() || a[st.top()] == a[i])
            st.push(i);
        else
            st.pop();
    }

    while (st.size() > k)
        st.pop();

    int last = n + 1;
    while (st.size() > 1)
    {
        int x = st.top();
        printf("%d %d\n", x, last - 1);
        last = x;
        st.pop();
    }
    printf("%d %d\n", 1, last - 1);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}