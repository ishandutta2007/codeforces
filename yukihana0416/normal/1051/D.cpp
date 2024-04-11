#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MOD = (int) 998244353;
const int maxn = (int) 1e5 + 20;

int n, k;
int dp[1005][2005][4];

inline void add(int &x, int y)
{
    x += y;
    if(x >= MOD) x -= MOD;
}

void work()
{
    cin >>n >>k;
    memset(dp, 0, sizeof(dp));

    dp[1][1][0] = 1;
    dp[1][1][3] = 1;
    dp[1][2][1] = dp[1][2][2] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= 2 * i; j++)
        {
            // k = 0
            add(dp[i + 1][j][0], dp[i][j][0]);
            add(dp[i + 1][j + 1][1], dp[i][j][0]);
            add(dp[i + 1][j + 1][2], dp[i][j][0]);
            add(dp[i + 1][j + 1][3], dp[i][j][0]);
            // k = 3
            add(dp[i + 1][j + 1][0], dp[i][j][3]);
            add(dp[i + 1][j + 1][1], dp[i][j][3]);
            add(dp[i + 1][j + 1][2], dp[i][j][3]);
            add(dp[i + 1][j][3], dp[i][j][3]);

            //k = 1
            add(dp[i + 1][j][0], dp[i][j][1]);
            add(dp[i + 1][j][1], dp[i][j][1]);
            add(dp[i + 1][j + 2][2], dp[i][j][1]);
            add(dp[i + 1][j][3], dp[i][j][1]);

            //k = 2
            add(dp[i + 1][j][0], dp[i][j][2]);
            add(dp[i + 1][j + 2][1], dp[i][j][2]);
            add(dp[i + 1][j][2], dp[i][j][2]);
            add(dp[i + 1][j][3], dp[i][j][2]);

        }
    }

    int ans = 0;
    for(int q = 0; q < 4; q++) add(ans, dp[n][k][q]);

    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    work();
    return 0;
}