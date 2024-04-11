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

int n, k;
bool a[1000][1000];
void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    if (((k - 1) << 1) < n)
    {
        for (int i = 0; i < k; i++)
            a[i << 1][i << 1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c", (a[i][j] ? 'R' : '.'));
            }
            printf("\n");
        }
    }
    else
    {
        printf("-1\n");
    }
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}