#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,k;

int x[N],y[N],c[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&y[i]);
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++)
        {
            int l=i,r=n+1;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(x[mid]-x[i]<=k)
                    l=mid;
                else
                    r=mid;
            }
            c[i]=l-i+1;
        }
        for(int i=n-1;i>=1;i--) 
            c[i]=max(c[i],c[i+1]);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            int l=0,r=i;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(x[i]-x[mid]<=k)
                    r=mid;
                else
                    l=mid;
            }
            ans=max(ans,i-r+1+c[i+1]);
        }
        printf("%d\n",ans);
    }
}