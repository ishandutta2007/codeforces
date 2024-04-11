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

#define ls rt<<1
#define rs rt<<1|1
#define mid (l+r)/2
#define ll long long
ll t[1000010<<2],laz[1000010<<2];
void php(int rt){t[rt]=t[ls]+t[rs];}
void phd(int rt,int l,int r){
    if(laz[rt]){
        t[ls]+=laz[rt]*(mid-l+1);
        laz[ls]+=laz[rt];

        t[rs]+=laz[rt]*(r-mid);
        laz[rs]+=laz[rt];
        
        laz[rt]=0;
    }
}
void upd(int rt,int l,int r,int x,int y,int z){
    if(x>y)return;
    if(x<=l&&r<=y){
        t[rt]+=1ll*z*(r-l+1);
        laz[rt]+=z;
        return;
    }
    phd(rt,l,r);
    if(x<=mid)upd(ls,l,mid,x,y,z);
    if(y>mid)upd(rs,mid+1,r,x,y,z);
    php(rt);
}
ll que(int rt,int l,int r,int x,int y){
    if(x>y)return 0;
    if(x<=l&&r<=y){
        return t[rt];
    }
    phd(rt,l,r);
    ll ret=0;
    if(x<=mid)ret+=que(ls,l,mid,x,y);
    if(y>mid)ret+=que(rs,mid+1,r,x,y);
    return ret;
}

int a[1000010];
int vis[1000010];
int pre[1000010];

int ans[1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;;
    for(int i=m+1;i>=2;i--){
        cin>>a[i];
        vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        a[i+m+1]=i;
    }
    for(int i=1;i<=n;i++){
        ans[i]=i;
        pre[i]=1;
    }
    int lim=n+m+1;

    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<endl;
    // }

    upd(1,1,lim,1,lim,n);

    for(int i=2;i<=lim;i++){
        //cout<<"beg:"<<i<<endl;

        upd(1,1,lim,pre[a[i]],i-1,-1);
        int tmp=n-que(1,1,lim,pre[a[i]],pre[a[i]]);

        //cout<<i<<" "<<tmp<<endl;
        ans[a[i]]=max(ans[a[i]],tmp);
        pre[a[i]]=i;

        //cout<<"end:"<<i<<endl;
    }

    for(int i=1;i<=n;i++){
        cout<<(vis[i]?1:i)<<" "<<ans[i]<<endl;
    }

}