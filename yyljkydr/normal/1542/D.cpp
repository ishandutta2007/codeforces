#include<bits/stdc++.h>
using namespace std;

#define double long double

const int N=511,P=998244353;

int n;

char op[N][2];

int a[N];

int f[N][N];

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",op[i]);
        if(op[i][0]=='+')
            scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(op[i][0]=='+')
        {
            int x=a[i];
            for(int j=1;j<=n;j++)
                for(int k=0;k<=n;k++)
                    f[j][k]=0;
            f[0][0]=1;
            for(int j=1;j<i;j++)
            {
                for(int k=0;k<=n;k++)
                    inc(f[j][k],f[j-1][k]);
                if(op[j][0]=='+')
                {
                    for(int k=0;k<=n;k++)
                        inc(f[j][k+(a[j]<=x)],f[j-1][k]);
                }
                else
                {
                    inc(f[j][0],f[j-1][0]);
                    for(int k=0;k<n;k++)
                        inc(f[j][k],f[j-1][k+1]);
                }       
            }
            for(int k=0;k<=n;k++)
                inc(f[i][k],f[i-1][k]);
            for(int j=i+1;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                    inc(f[j][k],f[j-1][k]);
                if(op[j][0]=='+')
                {
                    for(int k=0;k<=n;k++)
                        inc(f[j][k+(a[j]<x)],f[j-1][k]);
                }
                else
                {
                    for(int k=0;k<n;k++)
                        inc(f[j][k],f[j-1][k+1]);
                }       
            }
            int tot=0;
            for(int j=0;j<=n;j++)
                inc(tot,f[n][j]);
            inc(ans,1ll*tot*x%P);
        }
    printf("%d\n",ans);
}