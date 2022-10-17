#include<bits/stdc++.h>
using namespace std;
 
const int N=1e5+1e3+7;
 
typedef long long ll;
 
int n,q,k;
 
int a[N],b[N];
 
ll s[N];
 
int main()
{
    scanf("%d%d%d",&n,&q,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0]=0,a[n+1]=k+1;
    for(int i=1;i<=n;i++)
        b[i]=a[i+1]-a[i-1]+1-3;
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+b[i];  
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r)
            printf("%d\n",k-1);
        else
        {
            ll ans=0;
            ans+=a[l+1]+1-3;
            ans+=k+1-a[r-1]+1-3;
            if(l+1<=r-1)
                ans+=s[r-1]-s[l];
            printf("%lld\n",ans);
        }
    }
}