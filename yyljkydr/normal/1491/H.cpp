#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n,q,a[N],fa[N],tag[N],st[N],ed[N],ok[N],B;

void update(int x)
{
    for(int i=st[x];i<=ed[x];i++)
        a[i]=max(a[i]-tag[x],1ll);
    tag[x]=0;
    ok[x]=1;
    for(int i=st[x];i<=ed[x];i++)
    {
        fa[i]=a[i]/B==x?fa[a[i]]:i;
        ok[x]&=a[i]/B!=x||a[i]<=1;
    }
}

void change(int l,int r,int x)
{
    if(r/B==l/B)
    {
        for(int i=l;i<=r;i++)
            a[i]=max(a[i]-x,1ll);
        update(l/B);
        return;
    }
    int L,R;
    for(L=l;L%B!=0;L++)
        a[L]=max(a[L]-x,1ll);
    for(R=r;R%B!=B-1;R--)
        a[R]=max(a[R]-x,1ll);
    update(l/B);
    update(r/B);
    for(int i=L/B;i<=R/B;i++)
        if(ok[i])
            tag[i]+=x;
        else
        {
            tag[i]+=x;
            update(i);
        }
}

int query(int x,int y)
{
    if(x<=1||y<=1)
        return 1;
        while(fa[x]!=fa[y])
        {
            int fx=max(a[fa[x]]-tag[x/B],1ll),fy=max(a[fa[y]]-tag[y/B],1ll);
            if(fx<fy)
                swap(fx,fy),swap(x,y);
            x=fx;
            if(x<=1||y<=1)
          return 1;
        }
        
        while(x!=y)
        {
            if(max(a[x]-tag[x/B],1ll)<max(a[y]-tag[y/B],1ll))
                swap(x,y);
            x=max(a[x]-tag[x/B],1ll);
            if(x<=1||y<=1)
        return 1;
        }
    return x;
}

signed main()
{
    scanf("%lld%lld",&n,&q);
    B=sqrt(n);
    a[0]=a[1]=-1e9;
    for(int i=2;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        ed[i/B]=i;
    for(int i=n;i>=1;i--)
        st[i/B]=i;
    for(int i=0;i<=n/B;i++)
        update(i);
    while(q--)
    {
        int op;
        scanf("%lld",&op);
        if(op==1)
        {
            int l,r,x;
            scanf("%lld%lld%lld",&l,&r,&x);
            change(l,r,x);
        }
        else
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",query(x,y));
        }
    }
}