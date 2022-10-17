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

int n, a[N], ans, cnt[N];
void solve()
{
    ans = 0;
    for (int i = 0; i <= 100; i++)
        cnt[i] = 0;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        cnt[abs(a[i])]++;
    ans += min(cnt[0], 1);
    for (int i = 1; i <= 100; i++)
        ans += min(cnt[i], 2);
    printf("%d\n", ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}