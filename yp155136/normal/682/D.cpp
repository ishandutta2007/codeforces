#include <bits/stdc++.h>
using namespace std;

const int K = 11;
const int N = 1001;
const int INF = 0x3f3f3f3f;

int dp[K][N][N];
int mx[K][N][N];

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,K;
    cin >> n >> m >> K;
    string a,b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    for (int k=1;K>=k;k++)
    {
        for (int q=0;n>=q;q++)
        {
            dp[k][0][q] = -INF;
            dp[k][q][0] = -INF;
            mx[k][0][q] = -INF;
            mx[k][q][0] = -INF;
        }
        for (int i=1;n>=i;i++)
        {
            for (int j=1;m>=j;j++)
            {
                if (a[i] == b[j])
                {
                    dp[k][i][j] = max(dp[k][i-1][j-1] + 1,mx[k-1][i-1][j-1] + 1);
                }
                else
                {
                    dp[k][i][j] = -INF;
                }
                mx[k][i][j] = max(max(mx[k][i][j-1],mx[k][i-1][j]),dp[k][i][j]);
            }
        }
    }
    cout << mx[K][n][m] << endl;
}