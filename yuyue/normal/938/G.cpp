#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int LG=32,M=8e5+10;
struct LB{
	int b[LG];
	void ins(int x){
		DF(i,30,0){
			if (x>>i&1){
				if (!b[i]) return b[i]=x,void();
				else x^=b[i];
			}
		}
	}
	int qry(int x){
		DF(i,30,0) x=min(x,x^b[i]);
		return x;
	}
}oo;
struct node{
	int u,v,l,r,x;
}a[M];
int ct=0;
map<LL,int> hs;
vector<int> vt[M];
#define pii pair<int,int> 
#define mp make_pair
pii qs[M];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
void ins(int x,int l,int r,int ll,int rr,int t){
	if (l==ll && r==rr) {
		vt[x].pb(t);
		return ;
	}
	if (rr<=mid) ins(lc,l,mid,ll,rr,t);
	else if (ll>mid) ins(rc,mid+1,r,ll,rr,t);
	else ins(lc,l,mid,ll,mid,t),ins(rc,mid+1,r,mid+1,rr,t);
}
int f[M],sx[M],sz[M];
vector<int> ans;
int Fd(int x){
	if (f[x]==x) return x;
	return Fd(f[x]);
}
int gd(int x){
	if (f[x]==x) return 0;
	return sx[x]^gd(f[x]);
}
void solve(int x,int l,int r,LB lb){
	stack<node> s;
	F(i,0,SZ(vt[x])){
		int u=Fd(a[vt[x][i]].u),v=Fd(a[vt[x][i]].v);
		if (sz[u]>sz[v]) swap(u,v);
		int w=gd(a[vt[x][i]].u)^gd(a[vt[x][i]].v)^a[vt[x][i]].x;
		if (u==v){
			lb.ins(w);
		}	
		else {
			f[u]=v;
			sx[u]^=w; sz[v]+=sz[u]; 
			s.push(node{u,v,0,0,w});
		}
	}
	if (l==r) {
		if (qs[l].first){
			ans.pb(lb.qry(gd(qs[l].first)^gd(qs[l].second)));
		}
	}
	else {
		solve(lc,l,mid,lb);
		solve(rc,mid+1,r,lb);
	}
	while (s.size()){
		node t=s.top(); s.pop();
		sz[t.v]-=sz[t.u]; f[t.u]=t.u; 
		sx[t.u]^=t.x;
	}
}
int n,m,q;
int main(){
	n=read(); m=read();
	F(i,1,n) f[i]=i,sz[i]=1;
	F(i,1,m){
		int x=read(),y=read(),v=read();
		if (x>y) swap(x,y); LL o=1ll*x*n+y;
		hs[o]=++ct;
		a[ct]=node{x,y,0,-1,v};
	}
	q=read();
	F(i,1,q){
		int ty=read(),x=read(),y=read();
		if (x>y) swap(x,y);	LL o=1ll*x*n+y;
		if (ty==1){
			int v=read();
			hs[o]=++ct;
			a[ct]=node{x,y,i,-1,v};
		}
		else if (ty==2){
			a[hs[o]].r=i-1;
			hs[o]=0;
		}
		else qs[i]=mp(x,y);
	}
	F(i,1,ct) {
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].l<<" "<<a[i].r<<"    edge\n";
		if (a[i].r==-1) a[i].r=q;
		ins(1,0,q,a[i].l,a[i].r,i);
	}
	solve(1,0,q,oo);
	F(i,0,SZ(ans)) cout<<ans[i]<<"\n";
	return 0;
}