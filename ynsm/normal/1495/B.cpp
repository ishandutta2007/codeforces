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

int n, p[N], a[N], b[N], ma, mb, ca, cb;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && p[i - 1] < p[i])
            a[i] = a[i - 1] + 1;
        else
            a[i] = 1;
        if (ma < a[i])
            ma = a[i], ca = 0;
        if (ma == a[i])
            ca++;
    }
    for (int i = n; i >= 1; i--)
    {
        if (i < n && p[i + 1] < p[i])
            b[i] = b[i + 1] + 1;
        else
            b[i] = 1;
        if (mb < b[i])
            mb = b[i], cb = 0;
        if (mb == b[i])
            cb++;
    }
    if ((ma & 1) && ma == mb && ca == 1 && cb == 1)
    {
        for (int i = 0; i < n; i++)
            if (a[i] == ma && b[i] == mb)
            {
                printf("1");
                exit(0);
            }
    }
    printf("0");
}