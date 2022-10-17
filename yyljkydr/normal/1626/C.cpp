#include<bits/stdc++.h>
using namespace std;

const int N=111;

int T;

int n;

int h[N],k[N];

long long f[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&k[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&h[i]);
        for(int i=1;i<=n;i++)
            f[i]=1e18;
        for(int i=0;i<n;i++)
        {
            int bt=1e9;
            for(int j=i+1;j<=n;j++)
            {
                if(k[j]-k[i]<h[j])
                    break;
                bt=min(bt,k[j]-h[j]+1);
                //t=k[j]-h[j]
                f[j]=min(f[j],f[i]+1ll*(k[j]-bt+1)*(k[j]-bt+2)/2);
            }
        }
        printf("%lld\n",f[n]);
    }
}