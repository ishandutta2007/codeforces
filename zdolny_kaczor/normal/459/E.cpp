# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 3e5 + 44;
int dp[MN];
int temp[MN];
pair <int, pair <int, int> > E[MN];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[i] = make_pair(c, make_pair(b, a));
    }
    sort(E, E + m);
    for (int i = 0; i < m; )
    {
        int to;
        for (to = i; to < m && E[to].first == E[i].first; to++)
            ;
        for (int k = i; k < to; ++k)
            temp[E[k].second.second] = dp[E[k].second.second];
        for (int k = i; k < to; ++k)
            dp[E[k].second.first] = max(dp[E[k].second.first], temp[E[k].second.second] + 1);
        i = to;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, dp[i]);
    printf("%d\n", res);
}