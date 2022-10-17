#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

int T,n,x;

int sum[N],a[N],ans[N],suf[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
            sum[i]=-2e9;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            int s=0;
            for(int j=i;j<=n;j++)
                s+=a[j],sum[j-i+1]=max(sum[j-i+1],s);
        }
        suf[n]=sum[n];
        for(int i=n-1;i>=0;i--)
            suf[i]=max(sum[i],suf[i+1]);
        for(int k=0;k<=n;k++)
        {
            if(k)
                ans[k]=max({ans[k-1],suf[k]+k*x});
            else
                ans[k]=suf[0];
            printf("%d%c",ans[k]," \n"[k==n]);
        }
    }
}