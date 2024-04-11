#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T,n;

int a[N];

multiset<int>s,t;

int calc(int x,int y,int w)
{
    return x*y+(x+y)*w;
}

int chk(int w)
{
    int ret=0;
    int L=2,R=n;
    bool flag=0;
    int rp=1;
    for(int i=1;i<=n-1;i++)
    {
        int c[2]={a[1],a[rp]};
        int d[2]={a[L],a[R]};
        int p=-1,q=-1,ans=1e18;
        for(int a=0;a<2;a++)
            for(int b=0;b<2;b++)
            {
                if(calc(c[a],d[b],w)<ans)
                    ans=calc(c[a],d[b],w),p=a,q=b;
            }
        if(q==0)
            L++,rp=max(rp,L-1);
        else
            R--,rp=max(rp,R+1);
        ret+=ans;
    }
    return ret;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        int sum=0;
        for(int i=1;i<=n;i++)
            sum+=a[i];
        if(((__int128)sum+a[n]*(n-2))*(sum+a[1]*(n-2))>0)
            puts("INF");
        else
        {
            int l=-2e6,r=2e6;
            while(r-l>5)
            {
                int ml=l+(r-l)/3,mr=r-(r-l)/3;
                if(chk(ml)>chk(mr))
                    r=mr;
                else
                    l=ml;
            }
            int ans=-1e18;
            for(int i=l;i<=r;i++)
                ans=max(ans,chk(i));
            printf("%lld\n",ans);
        }
    }
}