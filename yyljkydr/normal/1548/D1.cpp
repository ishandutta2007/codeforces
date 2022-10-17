#include<bits/stdc++.h>
using namespace std;

const int N=6e3+1e2+7;

int n,x[N],y[N],cnt[2][2];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]),x[i]>>=1,y[i]>>=1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                cnt[j][k]=0;
        for(int j=1;j<=n;j++)
            if(i!=j)
                cnt[(x[j]-x[i])&1][(y[j]-y[i])&1]++;
        for(int t=0;t<2;t++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    for(int l=0;l<2;l++)
                        if(!((t|j)^(k|l)^((t^k)|(j^l))))
                            ans+=cnt[t][j]*cnt[k][l];
    }
    printf("%lld\n",(ans-(n-1)*n)/2/3);
}