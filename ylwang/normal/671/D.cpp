#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
struct node{
	int l,r;
	ll tag,x;
}seg[303030*30];
int root[303030],n,m,cnt,head[303030],tot;
struct edge{
	int to,nxt;
}g[1010101];
inline void made(int from,int to){
	g[++tot].to=to;g[tot].nxt=head[from];head[from]=tot;
}
vector<pair<int,ll> > Q[303030];
#define mid ((lb+rb)>>1)
#define inf (1e14)
inline void pushup(int rt){
	seg[rt].x=min(seg[seg[rt].l].x,seg[seg[rt].r].x);
}
inline void pushdown(int rt){
	if (seg[rt].tag){
		if (seg[rt].l) seg[seg[rt].l].tag+=seg[rt].tag,seg[seg[rt].l].x+=seg[rt].tag;
		if (seg[rt].r) seg[seg[rt].r].tag+=seg[rt].tag,seg[seg[rt].r].x+=seg[rt].tag;
		seg[rt].tag=0;
	}
}
void update(int &rt,int lb,int rb,int pos,ll x){
	if (!rt) rt=++cnt,seg[rt]=seg[0];
	if (lb==rb) return (void)(seg[rt].x=min(seg[rt].x,x));
	pushdown(rt);
	(mid>=pos?update(seg[rt].l,lb,mid,pos,x):update(seg[rt].r,mid+1,rb,pos,x));
	pushup(rt);
}
ll ANS;
void clear(int &rt,int lb,int rb,int pos){
	if (!rt) return;
	if (lb==rb) return (void)(ANS=seg[rt].x,seg[rt].x=inf);
	pushdown(rt);
	(mid>=pos?clear(seg[rt].l,lb,mid,pos):clear(seg[rt].r,mid+1,rb,pos));
	pushup(rt);
}
int Merge(int rto,int rtn,int lb,int rb,ll MIO,ll MIN){
	if (lb==rb&&rto&&rtn){
		seg[rto].x=min(seg[rto].x+min(seg[rtn].x,MIN),seg[rtn].x+min(seg[rto].x,MIO));
		return rto;
	}else if (rto==0&&rtn){
		seg[rtn].x=seg[rtn].x+MIO;
		seg[rtn].tag+=MIO;
		return rtn;
	}else if (rto&&rtn==0){  
		seg[rto].x=seg[rto].x+MIN;
		seg[rto].tag+=MIN;
		return rto;
	}else if (rto==0&&rtn==0) return 0;
	pushdown(rto);pushdown(rtn);
	seg[rto].l=Merge(seg[rto].l,seg[rtn].l,lb,mid,min(MIO,seg[seg[rto].r].x),min(MIN,seg[seg[rtn].r].x));
	seg[rto].r=Merge(seg[rto].r,seg[rtn].r,mid+1,rb,MIO,MIN);
	pushup(rto);
	return rto;
}
ll query(int rt,int lb,int rb,int l,int r){
	if (!rt||lb>r||rb<l) return inf;
	if (lb>=l&&rb<=r) return seg[rt].x;
	pushdown(rt);
	return min(query(seg[rt].l,lb,mid,l,r),query(seg[rt].r,mid+1,rb,l,r));
}
int dep[303030];
void dfs2(int u,int faa){
	dep[u]=dep[faa]+1;
	if (g[head[u]].nxt==0&&faa){
		for (auto x:Q[u]) update(root[u],1,n,dep[x.first],x.second);
		return;
	}
	for (int i=head[u];i;i=g[i].nxt){
		int v=g[i].to;
		if (v==faa) continue;
		dfs2(v,u);
		if (!root[u]) root[u]=root[v];
		else root[u]=Merge(root[u],root[v],1,n,inf,inf);
	}
	for (auto x:Q[u]) update(root[u],1,n,dep[x.first],x.second+query(root[u],1,n,dep[x.first],dep[u]));
	clear(root[u],1,n,dep[u]);
}
inline void init(){
	n=read(),m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		made(x,y);made(y,x);
	}
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		ll z=read();
		if (y!=x) Q[x].push_back(make_pair(y,z));
	}
}
inline void doit(){	
	ANS=seg[0].x=inf;
	dfs2(1,0);
}
inline void outit(){
	if (n==1) puts("0");
	else cout<<(ANS>=inf-100000?-1:ANS);
}
signed main(){
	init();
	doit();
	outit();
	return 0;
}