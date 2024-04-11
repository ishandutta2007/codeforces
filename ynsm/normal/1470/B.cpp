#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000100;

int n, q, a[N], val[N], cnt[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i] = val[a[i]];
        cnt[a[i]]++;
    }
    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, cnt[a[i]]);
        if (a[i] == 1 || cnt[a[i]] % 2 == 0)
            ans += cnt[a[i]];
        cnt[a[i]] = 0;
    }
    ans = max(ans, mx);
    scanf("%d", &q);
    while (q--)
    {
        ll w;
        scanf("%lld", &w);
        if (w == 0)
            printf("%d\n", mx);
        else
            printf("%d\n", ans);
    }
}
int main()
{
    for (int i = 0; i < N; i++)
        val[i] = i;
    for (int i = 2; i * i < N; i++)
        for (int j = i; j < N; j += i)
            while (val[j] % (i * i) == 0)
                val[j] /= i * i;
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}