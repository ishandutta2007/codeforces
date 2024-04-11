#include<bits/stdc++.h>
#define maxn 150
#define maxm 10050
using namespace std;

int n,x;
int a[maxn];

double C[maxn][maxn];

double dp[maxn][maxm];

int main()  {
    scanf("%d%d",&n,&x);
    for (int i=C[0][0]=1;i<=n;++i)
        for (int j=C[i][0];j<=i;++j)
            C[i][j]=C[i-1][j-1]+C[i-1][j];

    dp[0][0]=1;
    for (int i=1;i<=n;++i)  {
        scanf("%d",a+i);
        for (int k=i;k;--k)
            for (int c=a[i];c<maxm;++c)
                dp[k][c]+=dp[k-1][c-a[i]];
    }

    double ans=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<maxm;++j)
            ans+=dp[i][j]/C[n][i]*min((double)j/i,((double)n/i+1.0)*x/2.0);
    
    printf("%.9lf\n",ans);
    return 0;
}