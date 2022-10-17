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

int n, m, q, ans, deg[N], cnt[N];
void add(int v, int u, int k){
    ans -= (deg[v] == cnt[v]);
    ans -= (deg[u] == cnt[u]);
    deg[v] += k;
    deg[u] += k;
    cnt[max(v, u)] += k;
    ans += (deg[v] == cnt[v]);
    ans += (deg[u] == cnt[u]);
}
int main()
{
    scanf("%d%d", &n, &m);
    ans = n;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        add(v, u, 1);
    }
    scanf("%d", &q);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int v, u;
            scanf("%d%d", &v, &u);
            add(v, u, 1);
        }
        if (t == 2)
        {
            int v, u;
            scanf("%d%d", &v, &u);
            add(v, u, -1);
        }
        if (t == 3)
        {
            printf("%d\n", ans);
        }
    }
}