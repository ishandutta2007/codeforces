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
ll a[N], b[N];
int get(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    int res = 0;
    int m = (l + r) >> 1;
    res = max(res, get(l, m - 1));
    res = max(res, get(m + 1, r));
    for(int i = l; i <= r; i++)
        b[i] = abs(a[i] - a[m]);
    for(int i = m - 1; i >= l; i--)
        b[i] = __gcd(b[i], b[i + 1]);
    for(int i = m + 1; i <= r; i++)
        b[i] = __gcd(b[i], b[i - 1]);
    for(int i = m, j = l; i <= r; i++){
        while(j <= m && __gcd(b[i], b[j]) == 1)
            j++;
        if(j <= m)
            res = max(res, i - j + 1);
    }
    return res;
}
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    printf("%d\n", get(0, n - 1));
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}