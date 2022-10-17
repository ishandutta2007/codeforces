#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k,z;

int a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k,&z);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[n+1]=0;
        int ans=0;
        for(int i=0;i<=z;i++)    
        {
            int p=1+k-i*2;
            if(p<=0)
                continue;
            int sum=0,mx=0;
            for(int j=1;j<=p;j++)
                sum+=a[j];
            for(int j=1;j<=p;j++)
                mx=max(mx,a[j]+a[j+1]);
            ans=max(ans,sum+mx*i);
        }
        printf("%d\n",ans);
    }
}