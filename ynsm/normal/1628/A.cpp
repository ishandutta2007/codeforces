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

int n, a[N];
vector<int> g[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--)
        g[a[i]].pb(i);
    int ptr = 0;
    vector<int> ans;
    while (ptr < n)
    {
        int x = 0;
        while (g[x].size())
            x++;
        for (int i = 0; i < x; i++)
            ptr = max(ptr, g[i].back());
        for (int i = 0; i < x; i++)
            while (!g[i].empty() && g[i].back() <= ptr)
                g[i].pop_back();
        ans.pb(x);
        ptr += 1;
    }
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
    for (int i = 0; i <= n; i++)
        g[i].clear();
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}