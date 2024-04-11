#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int a[N],b[N];

int pre[N],suf[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]),pre[i]=pre[i-1]+b[i];
        int s=0,ans=2e9;
        for(int i=n;i>=1;i--)
        {
            ans=min(ans,max(s,pre[i-1]));
            s+=a[i];
        }
        printf("%d\n",ans);
    }
}