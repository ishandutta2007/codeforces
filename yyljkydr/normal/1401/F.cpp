#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int n,a[N],q,m;

int swp[N],rev[N];

int c[N];

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=x&-x;
    }
}

int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

int qsum(int l,int r,int a,int b)
{
    if(a<=l&&r<=b)
    {
        int len=r-l+1;
        l--,r--;
        for(int i=m;i>=0&&(1<<i)>=len;i--)
        {
            if(rev[i])
                l^=(1<<(i+1))-1,r^=(1<<(i+1))-1;
            if(swp[i])
                l^=1<<i,r^=1<<i;
        }
        l++,r++;
        if(l>r)
            swap(l,r);
        return query(r)-query(l-1);
    }
    int mid=(l+r)>>1;
    int ret=0;
    if(a<=mid)
        ret+=qsum(l,mid,a,b);
    if(b>mid)
        ret+=qsum(mid+1,r,a,b);
    return ret;
}

signed main()
{
    scanf("%lld%lld",&m,&q);
    n=1<<m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),add(i,a[i]);
    while(q--)
    {
        int op;
        scanf("%lld",&op);
        if(op==1)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            x--;
            for(int i=m;i>=0;i--)
            {
                if(rev[i])
                    x^=(1<<(i+1))-1;
                if(swp[i])
                    x^=(1<<i);
            }
            x++;
            add(x,y-a[x]);
            a[x]=y;
        }
        if(op==2)
        {
            int k;
            scanf("%lld",&k);
            if(k)
                rev[k-1]^=1;
        }
        if(op==3)
        {
            int k;
            scanf("%lld",&k);
            swp[k]^=1;
        }
        if(op==4)
        {
            int l,r;
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",qsum(1,n,l,r));
        }
    }
}