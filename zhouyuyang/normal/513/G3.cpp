#include<bits/stdc++.h>
using namespace std;
const int Maxn=102;
int n,K;
double dp[2][Maxn][Maxn];
int a[Maxn];
inline int c2(int x){return x*(x-1)/2;}
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
int main()
{
    scanf("%d%d",&n,&K);
    if(K>875){
        printf("%.10lf\n",1.0*n*(n-1)/4);
        return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dp[0][i][j]=a[i]>a[j];
    int cs=1;
    for(int k=1;k<=K;k++,cs^=1)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                dp[cs][i][j]=0;
                dp[cs][i][j]+=dp[cs^1][i][j]*(c2(i)+c2(n-j+1)+c2(j-i));
                for(int sum=j+1;sum<=i+n;sum++)
                {
                    dp[cs][i][j]+=(1.0-dp[cs^1][sum-j][sum-i])*(min(i,sum-j)-max(1,sum-n)+1);
                    //if(i==1&&j==2)printf("%.4f\n",dp[cs][i][j]);
                }
                for(int sum=i+1;sum<=i+j-1;sum++)
                    dp[cs][i][j]+=dp[cs^1][sum-i][j]*(min(i,sum-i)-max(1,sum-j+1)+1);
                for(int sum=j+i+1;sum<=n+j;sum++)
                    dp[cs][i][j]+=dp[cs^1][i][sum-j]*(min(j,sum-j)-max(i+1,sum-n)+1);
                dp[cs][i][j]/=c2(n+1);
               // printf("i=%d j=%d dp=%.3f\n",i,j,dp[cs][i][j]);
            }
    }
    double ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans+=dp[cs^1][i][j];
    printf("%.12f\n",ans);
}