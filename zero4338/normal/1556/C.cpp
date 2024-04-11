#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=1e3+5;
int n;
ll ans;
int c[maxn];
struct segement
{
    #define L(u) u<<1
    #define R(u) u<<1|1
    struct node{ll lnum,rnum;}t[maxn<<2];
    void update(int u)
    {
        t[u].lnum=t[L(u)].lnum;t[u].rnum=t[R(u)].rnum;
        if(t[L(u)].rnum>t[R(u)].lnum)t[u].rnum+=t[L(u)].rnum-t[R(u)].lnum;
        else t[u].lnum+=t[R(u)].lnum-t[L(u)].rnum;
    }
    void build(int u,int l,int r)
    {
        if(l==r){if(l&1)t[u].rnum=c[l];else t[u].lnum=c[l];return;}
        int mid=(l+r)>>1;build(L(u),l,mid);build(R(u),mid+1,r);
        update(u);
    }
    pair<ll,ll>query(int u,int l,int r,int nl,int nr)
    {
        if(l>=nl&&r<=nr)return make_pair(t[u].lnum,t[u].rnum);
        int mid=(l+r)>>1;
        if(mid>=nl&&mid+1<=nr)
        {
            pair<ll,ll>la=query(L(u),l,mid,nl,nr),ra=query(R(u),mid+1,r,nl,nr),ret;
            ret.first=la.first;ret.second=ra.second;
            if(la.second>ra.first)ret.second+=la.second-ra.first;
            else ret.first+=ra.first-la.second;
            return ret;
        }
        else if(mid>=nl)return query(L(u),l,mid,nl,nr);
        else if(mid+1<=nr)return query(R(u),mid+1,r,nl,nr);
    }
}tr;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)c[i]=read();
    tr.build(1,1,n);
    for(int i=1;i<=n;i+=2)
    {
        for(int j=i+1;j<=n;j+=2)
        {
            if(j==i+1){ans+=min(c[i],c[j]);continue;}
            pair<ll,ll>val=tr.query(1,1,n,i+1,j-1);
            ans+=max(0ll,min(c[i]-val.first+1,c[j]-val.second+1));
        }
    }
    printf("%lld",ans);
    return 0;
}