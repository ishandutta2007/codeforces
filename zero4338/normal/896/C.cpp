#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>    
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=1e5+5;
int seed,vm;
int rnd()
{
    int ret=seed;
    seed=((ll)seed*7+13)%1000000007;
    return ret;
}
int n,m;
int qpow(ll a,int b,int mod)
{
    a%=mod;
    int ret=1;
    for(;b;b>>=1)
    {
        if(b&1)ret=(ll)ret*a%mod;
        a=a*a%mod;
    }
    return ret;
}
struct chtholly
{
    struct node
    {
        int l,r;
        mutable ll v;
        const bool operator <(const node &a)const{return l<a.l;}
    };
    set<node>t;
    auto split(int x)
    {
        if(x>n)return t.end();
        auto it=t.lower_bound(node{x,0,0});
        if(it!=t.end()&&it->l==x)return it;
        it--;
        if(it->r<x)return t.end();
        int l=it->l,r=it->r;ll v=it->v;
        t.erase(it);
        t.insert(node{l,x-1,v});
        return t.insert(node{x,r,v}).first;
    }
    void assign(int l,int r,int v)
    {
        auto itr=split(r+1),itl=split(l);
        t.erase(itl,itr);
        t.insert(node{l,r,v});
    }
    void add(int l,int r,int x)
    {
        auto itr=split(r+1),itl=split(l);
        for(;itl!=itr;itl++)itl->v+=x;
    }
    ll rank(int l,int r,int k)
    {
        vector<pair<ll,int>>vp;vp.clear();
        auto itr=split(r+1),itl=split(l);
        for(;itl!=itr;itl++)vp.push_back(make_pair(itl->v,itl->r-itl->l+1));
        sort(vp.begin(),vp.end());
        for(auto it:vp)
        {
            k-=it.second;
            if(k<=0)return it.first;
        }
    }
    int sum(int l,int r,int x,int mod)
    {
        int ret=0;
        auto itr=split(r+1),itl=split(l);
        for(;itl!=itr;itl++)
            ret=(ret+(ll)(itl->r-itl->l+1)%mod*qpow(itl->v,x,mod)%mod)%mod;
        return ret;
    }
}tr;
int a[maxn];
int main()
{
    n=read();m=read();seed=read();vm=read();
    for(int i=1;i<=n;i++)tr.t.insert(chtholly::node{i,i,a[i]=rnd()%vm+1});
    while(m--)
    {
        int opt=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x=0,y=0;
        if(l>r)swap(l,r);   
        if(opt==3)x=rnd()%(r-l+1)+1;
        else x=rnd()%vm+1;
        if(opt==4)y=rnd()%vm+1;
        if(opt==1)tr.add(l,r,x);
        else if(opt==2)tr.assign(l,r,x);
        else if(opt==3)printf("%lld\n",tr.rank(l,r,x));
        else if(opt==4)printf("%d\n",tr.sum(l,r,x,y));
    }
    return 0;
}