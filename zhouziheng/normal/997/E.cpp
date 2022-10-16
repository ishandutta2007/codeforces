#include<bits/stdc++.h>
#define maxn 120005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long
 
using namespace std;
ll N,Q,A[maxn],mn[maxn<<2],ans[maxn];
ll sum[maxn<<2],nd[maxn<<2],lz[maxn<<2];
ll siz[maxn<<2],tim[maxn<<2];
vector<pair<ll,ll> > ques[maxn];
struct node{ll v,l,r;};
stack<node> smx,smn;
 
inline ll read(){
    ll x=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
 
inline void pushup(ll k){
    if(mn[k<<1]==mn[k<<1|1]) mn[k]=mn[k<<1],siz[k]=siz[k<<1]+siz[k<<1|1];
    else if(mn[k<<1]<mn[k<<1|1]) mn[k]=mn[k<<1],siz[k]=siz[k<<1];
    else mn[k]=mn[k<<1|1],siz[k]=siz[k<<1|1];
}
inline void pushdown(ll k){
    if(lz[k]){
        lz[k<<1]+=lz[k],lz[k<<1|1]+=lz[k];
        mn[k<<1]+=lz[k],mn[k<<1|1]+=lz[k];
        lz[k]=0;
    }
    if(nd[k]){
        if(mn[k<<1]==mn[k]) sum[k<<1]+=siz[k<<1]*nd[k],nd[k<<1]+=nd[k];
        if(mn[k<<1|1]==mn[k]) sum[k<<1|1]+=siz[k<<1|1]*nd[k],nd[k<<1|1]+=nd[k];
        nd[k]=0; 
    }
}
inline void build(ll l,ll r,ll k){
    if(l==r){mn[k]=inf,siz[k]=1;return;}
    ll mid=l+r>>1;
    build(l,mid,k<<1),build(mid+1,r,k<<1|1);
    pushup(k); return;
}
inline void add(ll l,ll r,ll x,ll y,ll v,ll k){
    if(x<=l && r<=y){mn[k]+=v,lz[k]+=v;return;}
    pushdown(k); ll mid=l+r>>1;
    if(x<=mid) add(l,mid,x,y,v,k<<1);
    if(y>mid) add(mid+1,r,x,y,v,k<<1|1);
    pushup(k); return;
}
inline void ins(ll l,ll r,ll p,ll v,ll k){
    if(l==r){mn[k]=v;return;}
    pushdown(k); ll mid=l+r>>1;
    if(p<=mid) ins(l,mid,p,v,k<<1);
    else ins(mid+1,r,p,v,k<<1|1);
    pushup(k); return; 
}
inline ll query(ll l,ll r,ll x,ll y,ll k){
    if(x<=l && r<=y) return sum[k];
    pushdown(k); ll mid=l+r>>1,res=0;
    if(x<=mid) res+=query(l,mid,x,y,k<<1);
    if(y>mid) res+=query(mid+1,r,x,y,k<<1|1);
    return res;
}
 
int main(){
    N=read();
    for(ll i=1;i<=N;i++) A[i]=read();
    Q=read();
    for(ll i=1;i<=Q;i++){
        ll l=read(),r=read();
        ques[r].push_back(make_pair(i,l));
    }
    build(1,N,1);
    for(ll i=1;i<=N;i++){
        ll x=A[i],nl1=i,nl2=i;
        while(!smx.empty()){
            if(smx.top().v<x){
                ll l=smx.top().l,r=smx.top().r;
                add(1,N,l,r,x-smx.top().v,1);
                nl1=l,smx.pop();
            }
            else break;
        }
        while(!smn.empty()){
            if(smn.top().v>x){
                ll l=smn.top().l,r=smn.top().r;
                add(1,N,l,r,smn.top().v-x,1);
                nl2=l,smn.pop();
            }
            else break;
        }
        node tp1; tp1.v=x,tp1.l=nl1,tp1.r=i;
        node tp2; tp2.v=x,tp2.l=nl2,tp2.r=i;
        smx.push(tp1),smn.push(tp2);
        if(i-1) add(1,N,1,i-1,-1,1);
        ins(1,N,i,0,1);
        sum[1]+=siz[1],nd[1]+=1;
        for(ll j=0;j<ques[i].size();j++){
            ll l=ques[i][j].second,r=i,id=ques[i][j].first;
            ans[id]=query(1,N,l,r,1); 
        } 
    }
    for(ll i=1;i<=Q;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}