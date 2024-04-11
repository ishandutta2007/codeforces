#include<bits/stdc++.h>
#define mnl(k)  T[k].mnl
#define mxl(k)  T[k].mxl
#define mnr(k)  T[k].mnr
#define mxr(k)  T[k].mxr
#define tl(k)  T[k].tl
#define tr(k)  T[k].tr
#define sj(k)   T[k].sj
#define sl(k)   T[k].sl
#define sr(k)   T[k].sr
#define sjr(k)   T[k].sjr
#define slr(k)   T[k].slr
#define maxn 100050
#define modu 1000000007
using namespace std;
typedef long long LL;

LL add(LL x=0,LL y=0)   {   return (x+y)%modu;  };

int n,a[maxn];

map<int,int> pos;
int L[maxn],R[maxn];

struct node
{
    LL mnl,mxl,mnr,mxr;
    LL tl,tr;
    LL sj,sl,sr,slr,sjr;

    node(int j=0)   {
        // mnl=mnr=n+1,mxl=mxr=0;
        mnl=mxl=0,mnr=mxr=n+1;
        tl=tr=0;
        sj=j,sl=sr=a[j];
        slr=1LL*j*j%modu,sjr=1LL*j*a[j]%modu;
    }

    node operator * (const node& N) const   {
        node ans;
        ans.mnl=min(mnl,N.mnl),ans.mxl=max(mxl,N.mxl);
        ans.mnr=min(mnr,N.mnr),ans.mxr=max(mxr,N.mxr);

        ans.sj=add(sj+N.sj),ans.sl=add(sl+N.sl),ans.sr=add(sr+N.sr);
        ans.sjr=add(sjr+N.sjr),ans.slr=add(slr+N.slr);
        return ans;
    }

}   T[maxn<<2];

void upl(int k,int l,int r,int L)
{
    tl(k)=L;
    mnl(k)=mxl(k)=L;
    sl(k)=1LL*L*(r-l+1)%modu;
    slr(k)=1LL*L*sr(k)%modu;
    // cout<<"upl:"<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<sl(k)<<" "<<slr(k)<<endl;
}

void upr(int k,int l,int r,int R)
{
    tr(k)=R;
    mnr(k)=mxr(k)=R;
    sr(k)=1LL*R*(r-l+1)%modu;
    slr(k)=1LL*R*sl(k)%modu;
    sjr(k)=1LL*R*sj(k)%modu;
    // cout<<"upr:"<<k<<" "<<l<<" "<<r<<" "<<R<<" "<<sr(k)<<" "<<slr(k)<<" "<<sjr(k)<<endl;
}

void godown(int k,int l,int r)
{
    int mid=(l+r)>>1;
    int ls=k<<1,rs=k<<1|1;

    if (tl(k))
        upl(ls,l,mid,tl(k)),upl(rs,mid+1,r,tl(k)),tl(k)=0;

    if (tr(k))
        upr(ls,l,mid,tr(k)),upr(rs,mid+1,r,tr(k)),tr(k)=0;
}

void build(int k,int l,int r)
{
    if (l==r)
        T[k]=node(l);
    else
    {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        T[k]=T[k<<1]*T[k<<1|1];
    }
}

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",a+i);

        R[i]=n;
        L[i]=pos[a[i]]+1;
        R[pos[a[i]]]=i-1;
        pos[a[i]]=i;
    }
    build(1,1,n);
    mnl(0)=mnr(0)=n+1;
    mxl(0)=mxr(0)=0;
}

void change(int k,int l,int r,int a,int b,int L,int R)
{
    int mid=(l+r)>>1;
    if (a<=l&&r<=b)
    {
        // cout<<"change:"<<k<<"("<<mxl(k)<<","<<mnr(k)<<") "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<L<<" "<<R<<endl;
        if (mxl(k)<L)  upl(k,l,r,L);
        if (mnr(k)>R)  upr(k,l,r,R);


        if ((mxl(k)<L||mnl(k)>=L)&&(mnr(k)>R||mxr(k)<=R))   ;
        else
        {
            godown(k,l,r);
            change(k<<1,l,mid,a,b,L,R);
            change(k<<1|1,mid+1,r,a,b,L,R);

            T[k]=T[k<<1]*T[k<<1|1];
        }

    } else
    {
        godown(k,l,r);
        if (a<=mid)
            change(k<<1,l,mid,a,b,L,R);
        if (b>mid)
            change(k<<1|1,mid+1,r,a,b,L,R);
        T[k]=T[k<<1]*T[k<<1|1];
    }
    // cout<<"after:"<<k<<"("<<sjr(k)<<" "<<slr(k)<<" "<<sl(k)<<" "<<sj(k)<<")"<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
}

node query(int k,int l,int r,int a,int b)
{
    if (a>r||l>b)   return T[0];

    // cout<<"query:"<<k<<"("<<sjr(k)<<" "<<slr(k)<<" "<<sl(k)<<" "<<sj(k)<<")"<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    if (a<=l&&r<=b) return T[k];
    godown(k,l,r);
    int mid=(l+r)>>1;
    return query(k<<1,l,mid,a,b)*query(k<<1|1,mid+1,r,a,b);
}

void travel(int k,int l,int r)
{
    if (l==r)
        cout<<l<<" "<<mnl(k)<<" "<<mnr(k)<<endl;
    else
    {
        godown(k,l,r);
        int mid=(l+r)>>1;
        travel(k<<1,l,mid);
        travel(k<<1|1,mid+1,r);
    }
}


void solve()
{
    // for (int i=1;i<=n;++i)
    //     cout<<a[i]<<" ";
    // cout<<endl;

    LL ans=0;
    for (int i=1,last=1;i<=n;++i)
    {
        last=max(last,L[i]);
        change(1,1,n,last,i,L[i],R[i]);
        node N=query(1,1,n,last,i);

        // cout<<i<<" "<<last<<" "<<N.sjr<<" "<<N.slr<<" "<<N.sl<<" "<<N.sj<<" ~ "<<N.sjr-N.slr+(N.sl-N.sj)*i<<endl;
        ans+=N.sjr-N.slr+(N.sl-N.sj)*i;
        ans%=modu;
        ans=(ans+modu)%modu;

        // cout<<endl;
        // travel(1,1,n);
        // cout<<endl;
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}