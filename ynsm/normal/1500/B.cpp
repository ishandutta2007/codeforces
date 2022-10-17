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

int n, m, a[N], b[N], c[N];
ll k;
int main()
{
    for (int i = 0; i < N; i++)
        a[i] = b[i] = -1;
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        --x;
        a[x] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        --x;
        b[x] = i;
    }
    for (int i = 0; i < m; i++)
        c[i] = -1;
    for (int i = 0; i < m; i++)
    {
        int x = 1ll * i * n % m;
        if (c[x] == -1)
            c[x] = i;
    }
    ll per = 1ll * n * m / __gcd(n, m);
    ll l = 0, r = 1e18;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        ll cur = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i] == -1 || b[i] == -1)
                continue;
            int x = (b[i] - a[i]) % m;
            if (x < 0)
                x += m;
            if (c[x] == -1)
                continue;
            ll f = a[i] + 1ll * c[x] * n;
            cur += mid / per;
            if (f < mid % per)
                cur++;
        }
        cur = mid - cur;
        if (cur < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%lld", l);
}