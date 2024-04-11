#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

multiset<int>s[2];

int cnt;

struct T{
    int ls,rs;
    int sum,sz;
}t[N*32+1];

int rt;

void ins(int &x,int l,int r,int v,int p)
{
    if(!x)
        x=++cnt;
    t[x].sum+=(v-1e9)*p;
    t[x].sz+=p;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    if(v<=mid)
        ins(t[x].ls,l,mid,v,p);
    else
        ins(t[x].rs,mid+1,r,v,p);
}

int query(int x,int l,int r,int k)
{
    if(l==r)
        return k*(l-1e9);
    int mid=(l+r)>>1;
    if(t[t[x].rs].sz>=k)
        return query(t[x].rs,mid+1,r,k);
    else
        return t[t[x].rs].sum+query(t[x].ls,l,mid,k-t[t[x].rs].sz);
}

int n,S;

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        int tp,x;
        scanf("%lld%lld",&tp,&x);
        if(x>0)
        {
            s[tp].insert(x);
            S+=x;
            ins(rt,0,2e9,x+1e9,1);
        }
        else
        {
            x=-x;
            s[tp].erase(s[tp].find(x));
            S-=x;
            ins(rt,0,2e9,x+1e9,-1);
        }
        int rs=query(rt,0,2e9,s[1].size());
        int ans=rs*2+(S-rs);
        if(!s[1].empty()&&(s[0].empty()||*s[1].begin()>*s[0].rbegin()))
        {
            ans-=*s[1].begin();
            ans+=s[0].empty()?0:*s[0].rbegin();
        }
        printf("%lld\n",ans);
    }
}