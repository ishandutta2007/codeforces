#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e2+7;

int n,k;

int a[N];

long long s[N];

int getw(int x)
{
    if(!x)
        return 0;
    if(!a[abs(x)])
        return k;
    return x>0?a[x]:-a[-x];
}

int main()
{
    scanf("%d%d",&n,&k);
    int cnt=0;
    long long ss=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),cnt+=!a[i],ss+=a[i];
    if(ss+1ll*cnt*k<0||ss-1ll*cnt*k>0)
    {
        puts("-1");
        return 0;
    }
    n++;
    long long ans=-1e18;
    for(int i=0;i<n;i++)
    {
        fill(s,s+n,1e18);
        s[i]=0;
        for(int j=(i+1)%n,t=0;t<=n*2;j=(j+1)%n,t++)
        {
            int l=(j-1+n)%n;
            s[j]=min(s[j],s[l]+getw(j));
        }
        for(int j=(i-1+n)%n,t=0;t<=n*2;j=(j-1+n)%n,t++)
        {
            int l=(j+1)%n;
            s[j]=min(s[j],s[l]+getw(-l));
        }
        long long mn=1e18,mx=-1e18;
        for(int i=0;i<n;i++)
            mx=max(mx,s[i]),mn=min(mn,s[i]);
        ans=max(ans,mx-mn+1);
    }
    printf("%lld\n",ans);
}