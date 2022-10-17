#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int T,n,a[N],b[N],c[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        ll curLen=abs(a[2]-b[2])+2;
        ll ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=max(ans,curLen+c[i]-1);
            curLen+=min(a[i+1],b[i+1])-1+c[i]-max(a[i+1],b[i+1])+2;
            curLen=max(curLen,1ll*abs(a[i+1]-b[i+1])+2);
            if(a[i+1]==b[i+1])
                curLen=2;
        }
        printf("%lld\n",ans); 
    }
}