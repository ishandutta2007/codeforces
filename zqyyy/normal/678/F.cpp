#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=4e5+7;
const ll INF=9e18;
struct node{int l,r;}d[N];
int n,m,num,lsh[N],q[N];
ll ans[N];
struct Line{int k,b;}a[N];
inline ll calc(int i,int x){return 1ll*a[i].k*x+a[i].b;}
struct Lc_Tree{
    int tot,t[N<<1],ls[N<<1],rs[N<<1];
    inline void clear(){
	while(tot)t[tot]=ls[tot]=rs[tot]=0,tot--;
    }
    void modify(int &p,int l,int r,int x){
	if(!p){p=++tot,t[p]=x;return;}
	int mid=(l+r)>>1;
	if(calc(t[p],lsh[mid])<calc(x,lsh[mid]))swap(t[p],x);
	if(l==r)return;
	if(calc(t[p],lsh[l])<calc(x,lsh[l]))modify(ls[p],l,mid,x);
	if(calc(t[p],lsh[r])<calc(x,lsh[r]))modify(rs[p],mid+1,r,x);
    }
    ll query(int p,int l,int r,int x){
	if(!p)return -INF;
	ll res=calc(t[p],lsh[x]);if(l==r)return res;
	int mid=(l+r)>>1;
	if(x<=mid)res=max(res,query(ls[p],l,mid,x));
	else res=max(res,query(rs[p],mid+1,r,x));
	return res;
    }
}s[19];
int rt[19];
struct Segment_Tree{
    vector<int>t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    void modify(int p,int l,int r,int x,int y,int id){
	if(x<=l && r<=y){t[p].push_back(id);return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(ls,l,mid,x,y,id);
	if(y>mid)modify(rs,mid+1,r,x,y,id);
    }
    void solve(int p,int l,int r,int d){
	for(int i:t[p])s[d].modify(rt[d],1,num,i);
	if(l==r){
	    ans[l]=-INF;
	    for(int i=0;i<=d;i++)ans[l]=max(ans[l],s[i].query(rt[i],1,num,q[l]));
	}
	else{
	    int mid=(l+r)>>1;
	    solve(ls,l,mid,d+1),solve(rs,mid+1,r,d+1);
	}
	s[d].clear(),rt[d]=0;
    }
}T;
int main(){
    n=read();
    for(int i=1;i<=n;i++){
	int opt=read();
	if(opt==1)a[i].k=read(),a[i].b=read(),d[i].l=m+1,d[i].r=-1;
	else{
	    int x=read();
	    if(opt==2)d[x].r=m;
	    else q[++m]=x,lsh[m]=x;
	}
    }
    sort(lsh+1,lsh+m+1),num=unique(lsh+1,lsh+m+1)-lsh-1;
    for(int i=1;i<=m;i++)q[i]=lower_bound(lsh+1,lsh+num+1,q[i])-lsh;
    for(int i=1;i<=n;i++)
	if(d[i].l && d[i].l<=m){
	    if(d[i].r==-1)d[i].r=m;
	    if(d[i].l<=d[i].r)T.modify(1,1,m,d[i].l,d[i].r,i);
	}
    if(m)T.solve(1,1,m,0);
    for(int i=1;i<=m;i++)
	if(ans[i]>-INF)printf("%lld\n",ans[i]);
	else puts("EMPTY SET");
    return 0;
}