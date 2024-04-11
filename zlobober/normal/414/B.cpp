#include <cstdio>
using namespace std;

const int N = 2050;

const int MOD = 1000 * 1000 * 1000 + 7;

int D[N][N];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    D[0][1] = 1;
    for (int l = 0; l < k; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                D[l + 1][j] += D[l][i];
                if (D[l + 1][j] >= MOD)
                    D[l + 1][j] -= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += D[k][i];
        if (ans >= MOD)
            ans -= MOD;
    }
    printf("%d\n", ans);
}