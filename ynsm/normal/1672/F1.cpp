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
int p[N];

int a[N], cnt[N];
vector<int> g[N];

void solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        g[a[i]].pb(i);
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(p + 1, p + 1 + n, [](int i, int j)
         { return cnt[i] > cnt[j]; });

    while (true)
    {
        int k = 1;
        while (k <= n && cnt[p[k]] != 0)
            k++;
        if (k == 1)
            break;
        vector<int> v;
        for (int i = 1; i < k; i++)
        {
            v.pb(g[p[i]].back());
            g[p[i]].pop_back();
            cnt[p[i]]--;
        }
        for (int i = 0; i + 1 < v.size(); i++)
            swap(a[v[i]], a[v[i + 1]]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}