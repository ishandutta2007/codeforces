#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define SZ(x) (int)x.size()-1
#define pb push_back
using namespace std;
const int M=2e5+10;
vector<int> v[M]; 
int n,m,q,nxt[M<<1],to[M<<1],head[M],cnt; 
void add(int x,int y){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; 
}
int dfn[M],low[M],tot,ttp,st[M],dcc; 
void tarjan(int x){
	dfn[x]=low[x]=++tot; st[++ttp]=x;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (dfn[y]) low[x]=min(low[x],dfn[y]); 
		else {
			tarjan(y); 
			low[x]=min(low[x],low[y]); 
			if (low[y]==dfn[x]){
				dcc++;
				add(dcc,x); add(x,dcc); 
//				cout<<dcc<<" - "<<x<<"  ff\n";
				while (1){
					int w=st[ttp];
					ttp--;
//					cout<<dcc<<" - "<<w<<"  ff\n";
					add(dcc,w); add(w,dcc); 
					if (w==y) break;
				}
			}
		}
	}
//	cout<<x<<" "<<low[x]<<" "<<dfn[x]<<"ttl\n";
}
int dn[M],tn,fa[M],dep[M],sz[M],w[M],son[M],tp[M],wn[M];
multiset<int> s[M];  
void dfs(int x,int baba){
	dep[x]=dep[baba]+1; fa[x]=baba; sz[x]=1;    
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==baba) continue; 
		dfs(y,x); 
		sz[x]+=sz[y];
		if (x>n) s[x].insert(w[y]);
		if (sz[y]>sz[son[x]]) son[x]=y; 
	}
}
void dfs1(int x,int hp){
	dn[x]=++tn; tp[x]=hp; wn[tn]=x; 
//	cout<<tp[x]<<" "<<x<<"   dfs gg\n";
	if (son[x]) dfs1(son[x],hp);
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa[x] || y==son[x]) continue; 
		dfs1(y,y); 
	}
}
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
int mi[M<<3],lg[M];
void pu(int x){
	mi[x]=min(mi[lc],mi[rc]); 
}
void build(int x,int l,int r){
	mi[x]=2e9;
	if (l==r) {
		if (wn[l]>n) mi[x]=*s[wn[l]].begin();
		return ;
	}
	build(lc,l,mid); build(rc,mid+1,r);
	pu(x);
}
void upd(int x,int l,int r,int p){
	if (l==r) {
		mi[x]=*s[wn[l]].begin();
		return ;
	}
	if (p<=mid) upd(lc,l,mid,p); 
	else upd(rc,mid+1,r,p);
	pu(x);
}
int qqry(int x,int l,int r,int ll,int rr){
//	cout<<x<<" "<<l<<" "<<r<<"  gd\n";
	if (l==ll && r==rr) return mi[x];
	if (rr<=mid) return qqry(lc,l,mid,ll,rr);
	if (ll>mid) return qqry(rc,mid+1,r,ll,rr); 
	return min(qqry(lc,l,mid,ll,mid),qqry(rc,mid+1,r,mid+1,rr));
}
int qry(int x,int y){
	int ret=2e9; 
	while (tp[x]!=tp[y]){
		if (dep[tp[x]]<dep[tp[y]]) swap(x,y);
		ret=min(ret,qqry(1,1,tn,dn[tp[x]],dn[x])); 
//		cout<<x<<" "<<dn[tp[x]]<<" -- "<<dn[x]<<"   qry\n"; 
		x=fa[tp[x]];
	}
	if (dn[x]>dn[y]) swap(x,y); 
	if (x>n) {
		if (fa[x]) ret=min(ret,w[fa[x]]); 
	}
	else ret=min(ret,w[x]);
//	cout<<dn[x]<<" -- "<<dn[y]<<"   qry\n";
	return min(ret,qqry(1,1,tn,dn[x],dn[y]));
}
int main(){
	ios::sync_with_stdio(0); 
	cin>>n>>m>>q; 
	F(i,1,n) cin>>w[i];
	F(i,1,m){
		int x,y; cin>>x>>y; 
		v[x].pb(y); v[y].pb(x);
	}
	dcc=n; tarjan(1);
	F(i,2,dcc) lg[i]=lg[i>>1]+1; 
	dfs(1,0); dfs1(1,1);
	build(1,1,tn);
//	cout<<"fuck\n";
	while (q--){
		char c; int x,y; cin>>c>>x>>y; 
		if (c=='A'){
			cout<<min(w[x],min(w[y],qry(x,y)))<<"\n"; 
		}
		else {
			int o=fa[x],old=0,nnw=0;
			if (o){
				old=*s[o].begin();
				s[o].erase(s[o].lower_bound(w[x]));
				s[o].insert(y);
				nnw=*s[o].begin();
				if (old^nnw) upd(1,1,tn,dn[o]);
			}
			w[x]=y;
		}
	}
	return 0;
}