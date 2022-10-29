#include <bits/stdc++.h>
using namespace std;

int a[223456];
int dp[3][223456];

const int INF = 1000000007;

int main ()
{
    string s;
    cin  >> s;
    int n = (int)s.size();
    for (int i=1;n>=i;i++)
    {
        a[i] = (s[i-1] - '0') % 3;
    }
    dp[0][0] = 0;
    dp[1][0] = dp[2][0] = -INF;
    for (int i=1;n>=i;i++)
    {
        dp[0][i] = dp[1][i] = dp[2][i] = -INF;
        dp[ a[i] ][i] = max( max( dp[0][i-1] , dp[1][i-1] ) , dp[2][i-1] ) + (a[i]%3 == 0);
        for (int j=0;3>j;j++)
        {
            dp[ (j + a[i])%3 ][i] = max(dp[ (j + a[i])%3 ][i] , dp[j][i-1] + ( (j + a[i])%3 == 0 ));
        }
        /*for (int j=0;3>j;j++)
        {
            cout << "dp[ " << j << "][" << i << "] = " << dp[j][i] << endl;
        }*/
    }
    cout << max( max(dp[0][n] , dp[1][n]) , dp[2][n] ) << endl;
}