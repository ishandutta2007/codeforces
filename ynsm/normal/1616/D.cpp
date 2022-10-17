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

int n, a[N], x, ans;

void solve()
{
    ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for (int i = 1; i <= n; i++)
        a[i] -= x;
    ll cur = 0, mx = -INF, pref = -INF;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, pref);
        pref = cur;
        cur += a[i];
        // cerr << a[i] << " ";
        if (cur < mx)
        {
            // cerr << "B ";
            ans++;
            cur = 0;
            pref = mx = -INF;
        }
        // cerr << endl;
    }
    printf("%d\n", n - ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}