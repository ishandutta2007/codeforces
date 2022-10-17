#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,P=998244353;

int T,n,a[N],k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        long long ans=1;
        for(int i=1;i<=k;i++)
            ans=ans*i%P;
        for(int i=1;i<=n-k;i++)
            if(a[i]==-1)
                ans=ans*(i+k)%P;
            else if(a[i]==0)
                ans=ans*(k+1)%P;
        for(int i=n-k+1;i<=n;i++)
            ans=ans*(a[i]==0||a[i]==-1)%P;
        printf("%lld\n",ans);
    }
}