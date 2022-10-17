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

bool sqr(int x)
{
    int y = sqrt(x);
    while (y * y > x)
        y--;
    while (y * y < x)
        y++;
    return y * y == x;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n % 2 == 0 && sqr(n / 2))
        {
            printf("YES\n");
        }
        else if (n % 4 == 0 && sqr(n / 4))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}