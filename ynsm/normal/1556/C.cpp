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
ll ans;
void f(ll a, ll b, ll c)
{
    if (b < a)
        return;
    // [a, b] [1, c]

    // cerr << "F " << a << " " << b << " " << c << endl;
    ans += max(0ll, min(b, c) - max(a, 1ll) + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i += 2)
    {
        ll L = 1, R = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (j & 1)
            {
                // close
                f(L, R, a[j]);
                L -= a[j], R -= a[j];
                L = max(L, 0ll);
            }
            else
            {
                // open
                L += a[j], R += a[j];
            }

            // cerr << i << " " << j << " " << ans << endl;
        }
    }
    printf("%lld", ans);
}