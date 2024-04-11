#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}

#define ls rt<<1
#define rs rt<<1|1
#define mid (l+r)/2
ll t[1000010<<2],laz[1000010<<2];
void php(int rt){t[rt]=min(t[ls],t[rs]);}
void phd(int rt){
    t[ls]+=laz[rt];
    laz[ls]+=laz[rt];

    t[rs]+=laz[rt];
    laz[rs]+=laz[rt];

    laz[rt]=0;
}
void upd(int rt,int l,int r,int x,int y,int z){
    if(x<=l&&r<=y){
        t[rt]+=z;
        laz[rt]+=z;
        return;
    }
    phd(rt);
    if(x<=mid)upd(ls,l,mid,x,y,z);
    if(y>mid)upd(rs,mid+1,r,x,y,z);
    php(rt);
}
ll que(int rt,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return t[rt];
    }
    phd(rt);
    ll ret=1ll<<60;
    if(x<=mid)ret=min(ret,que(ls,l,mid,x,y));
    if(y>mid)ret=min(ret,que(rs,mid+1,r,x,y));
    return ret;
}

int x[200010],y[200010];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    for(int i=1;i<=n;i++){
        upd(1,1,n+1,x[i]+1,n+1,y[i]);
    }
    ll ans=1ll<<60;
    for(int i=1;i<n;i++){
        upd(1,1,n+1,x[i]+1,n+1,-y[i]);
        upd(1,1,n+1,1,x[i],y[i]);
        ans=min(ans,que(1,1,n+1,1,n+1));
    }
    cout<<ans<<endl;
}