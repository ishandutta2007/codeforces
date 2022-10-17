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

int n, a[N], b[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            a[i] &= 1;
        }
        ll ans = INF;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < n; i++)
                b[i] = a[i];
            ll res = 0;
            for (int i = 0, j = 0, q = 0; i < n; i++)
            {
                j = max(j, i);
                q = max(q, i);
                while (j < n && b[j])
                    j++;
                while (q < n && !b[q])
                    q++;
                if ((i ^ k) & 1)
                {
                    if (j < n)
                        res += j - i, b[j] ^= 1;
                    else
                        res = INF;
                }
                else
                {
                    if (q < n)
                        res += q - i, b[q] ^= 1;
                    else
                        res = INF;
                }
            }
            ans = min(res, ans);
        }
        if (ans == INF)
            ans = -1;
        printf("%lld\n", ans);
    }
}