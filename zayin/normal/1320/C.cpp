#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

const LL inf=1LL<<40;

struct node {
    LL val,tag;
} T[maxn<<2];
#define tag(k) T[k].tag
#define val(k) T[k].val

int n,m,N;
int pos[maxn];
LL a[maxn],ca[maxn];
LL b[maxn],cb[maxn];

LL sb[maxn];
vector<int> B;

void update(int k)  {
    val(k)=max(val(k<<1),val(k<<1|1));
}

void renew(int k,LL d)  {
    tag(k)+=d,val(k)+=d;
}

void godown(int k)  {
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void build(int k,int l,int r)    {
    if (l==r)
        val(k)=-sb[l];
    else    {
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        update(k);
    }
    // cout<<l<<" "<<r<<" "<<val(k)<<endl;
}

void change(int k,int l,int r,int p,LL d)   {
    if (p>r) return ; 
    if (p<=l)
        renew(k,d);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        change(k<<1,l,mid,p,d);
        change(k<<1|1,mid+1,r,p,d);
        update(k);
    }
    // cout<<"change:"<<l<<" "<<r<<" "<<p<<" "<<d<<" "<<val(k)<<endl;
}

int g,guai[maxn];
int x[maxn],y[maxn],z[maxn];

int main()  {
    scanf("%d%d%d",&n,&m,&g);
    for (int i=1;i<=n;++i)  {
        scanf("%lld%lld",a+i,ca+i);
        pos[i]=i;

        // cout<<i<<":"<<a[i]<<" "<<ca[i]<<endl;
    }
    for (int i=1;i<=m;++i)  {
        scanf("%lld%lld",b+i,cb+i);
        B.push_back(b[i]);
    }

    sort(B.begin(),B.end());
    B.resize(unique(B.begin(),B.end())-B.begin());
    N=B.size();

    // cout<<"n:"<<N<<endl;

    auto id=[&](const int x)    {
        return lower_bound(B.begin(),B.end(),x)-B.begin()+1;
    };

    for (int i=1;i<=N;++i) sb[i]=inf;
    for (int i=1;i<=m;++i)
        sb[id(b[i])]=min(sb[id(b[i])],cb[i]);

        
    // for (int i=1;i<=n;++i)
    //     cout<<a[pos[i]]<<" "<<ca[pos[i]]<<endl;
    
    sort(pos+1,pos+n+1,[&](const int& i,const int& j)   {
        return a[i]<a[j];
    });
    
    // for (int i=1;i<=n;++i)
    //     cout<<a[pos[i]]<<" "<<ca[pos[i]]<<endl;

    for (int i=1;i<=g;++i)
        scanf("%d%d%d",x+i,y+i,z+i),guai[i]=i;//,swap(x[i],y[i]);
    sort(guai+1,guai+g+1,[&](const int& i,const int& j)   {
        return x[i]<x[j];
    });

    // for (int i=1;i<=g;++i)
    //     cout<<x[guai[i]]<<" "<<y[guai[i]]<<" "<<z[guai[i]]<<endl;

    // for (int i=1;i<=n;++i)
    //     cout<<a[pos[i]]<<" "<<ca[pos[i]]<<endl;
    // cout<<"???"<<endl;
    build(1,1,N);
    // for (int i=1;i<=n;++i)
    //     cout<<a[pos[i]]<<" "<<ca[pos[i]]<<endl;

    LL ans=-inf;
    for (int k=1,j=1;k<=n;++k)  {
        // cout<<"k:"<<k<<" "<<a[pos[k]]<<" "<<ca[pos[k]]<<endl;
        while (j<=g&&a[pos[k]]>x[guai[j]])
            // cout<<"upd:"<<a[pos[k]]<<" "<<k<<" "<<j<<endl,
            change(1,1,N,id(y[guai[j]]+1),z[guai[j]]),++j;
        // cout<<k<<":"<<val(1)<<endl;
        ans=max(ans,-ca[pos[k]]+val(1));
    }
    printf("%lld\n",ans);
    return 0;
}