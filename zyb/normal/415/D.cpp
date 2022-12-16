#include <stdio.h>
#include <string.h>

using namespace std ;

const int maxn = 2012 ;
const int MOD = 1000000007 ;

int dp[maxn][maxn] ;

int main()
{
    int n,k ;
    while(~scanf("%d %d",&n,&k))
    {
        int num = 0 ;
        for(int i = 1 ; i < maxn ; i++)
            dp[i][1] = 1;
        for(int j = 1 ; j < k ; j++)
        {
            for(int i = 1 ; i <= n ; i ++)
            {
                for(int h = i ; h <= n ; h += i)
                {
                    dp[h][j+1] = (dp[h][j+1]+dp[i][j])%MOD ;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            num += dp[i][k] ;
            num %= MOD ;
        }
        printf("%d\n",num) ;
    }
    return 0 ;
}