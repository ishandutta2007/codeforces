#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define M 100005
int a[M][15];
int dp[M][15];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            tmp+=a[1][i];
            dp[1][i]=tmp;
        }
        tmp=0;
        for(int i=1;i<=m;i++)
        {
            tmp+=a[i][1];
            dp[i][1]=tmp;
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j])+a[i][j];
            }
        }
        for(int i=1;i<m;i++)
        {
            printf("%d ",dp[i][n]);
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}