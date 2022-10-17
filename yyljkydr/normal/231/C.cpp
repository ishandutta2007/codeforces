#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],k;

long long s[N];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0,p=-1;
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=0,r=i;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(1ll*a[i]*(i-mid+1)-(s[i]-s[mid-1])<=k)
                r=mid;
            else
                l=mid;
        }
        if(i-r+1>ans)
            ans=i-r+1,p=a[i];
    }
    printf("%d %d\n",ans,p);
}