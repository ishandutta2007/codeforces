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
        int c, d;
        scanf("%d%d", &c, &d);
        if ((c ^ d) & 1)
        {
            printf("-1\n");
            continue;
        }
        if (c == d)
        {
            if (c)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        printf("2\n");
    }
}