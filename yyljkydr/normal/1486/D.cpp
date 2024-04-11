#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],k,b[N],s[N];

bool chk(int x)
{
    for(int i=1;i<=n;i++)
        b[i]=a[i]>=x?1:-1;
    int ret=0,mn=1e9;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+b[i];
        if(i-k>=0)
            mn=min(mn,s[i-k]);
        ret|=i>=k&&s[i]-mn>0;
    }
    return ret;
}

int main()
{  
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(chk(mid))
            l=mid;
        else
            r=mid;   
    }
    printf("%d\n",l);
}