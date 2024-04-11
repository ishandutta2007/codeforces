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

int n, a[N], s, k;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        s = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            s += a[i];
        }
        sort(a, a + n);
        if (s == k)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int p = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == k)
                p = a[i];
            else
            {
                printf("%d ", a[i]);
                k -= a[i];
            }
        }
        if (p != -1)
            printf("%d", p);
        printf("\n");
    }
}