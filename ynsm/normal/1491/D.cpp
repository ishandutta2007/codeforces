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
        int x, y;
        scanf("%d%d", &x, &y);
        int a = 0, b = 0;
        bool ok = 1;
        while (x || y)
        {
            if (x > y)
            {
                ok = 0;
                break;
            }

            if (x % 2 == 0 && a == 1)
            {
                x++;
                a = 0;
            }

            if (y % 2 == 1)
            {
                if (x % 2 == 1)
                {
                }
                else
                {
                    if (b > 0)
                    {
                        b--;
                    }
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            else
            {
                if (x % 2 == 1)
                {
                    b++;
                }
                else
                {
                }
            }
            x /= 2, y /= 2;
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}