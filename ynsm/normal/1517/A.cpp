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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll x;
        scanf("%lld", &x);
        if (x % 2050 != 0)
        {
            printf("-1\n");
            continue;
        }
        x /= 2050;
        ll y = 0;
        while (x)
            y += x % 10, x /= 10;
        printf("%lld\n", y);
    }
}