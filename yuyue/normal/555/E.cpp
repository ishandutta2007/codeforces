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
const int M=2e5+10;
set<LL> o;
vector<int> v[M],b[M],id[M];
int n,m,q;
int dfn[M],low[M],tt,s[M],tp,col[M],bcc;
bool in[M];
int tr[M],ct;
void tarjan(int x,int fr){
//	cout<<x<<"\n";
	dfn[x]=low[x]=++tt; s[++tp]=x; in[x]=1;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (id[x][i]==fr) continue; 
		if (!dfn[y]) tarjan(y,id[x][i]),low[x]=min(low[x],low[y]);
		else if (in[y]) low[x]=min(low[x],dfn[y]);
	}
	if (low[x]==dfn[x]){
		bcc++;
		do{
			col[s[tp]]=bcc;
			in[s[tp]]=0;
		}while (s[tp--]!=x);
	}
}
int lg[M],f[M][18],dep[M];
void dfs(int x,int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1;	tr[x]=ct;
	F(i,1,lg[dep[x]]) f[x][i]=f[f[x][i-1]][i-1];
	F(i,0,SZ(b[x])){
		int y=b[x][i];
		if (y==fa) continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	F(i,0,lg[del]) if (del>>i&1) x=f[x][i];
	if (x==y) return x;
	DF(i,lg[dep[x]],0) if (f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int up[M],dn[M];
bool fuck;
void dfs1(int x,int fa){
	F(i,0,SZ(b[x])){
		int y=b[x][i];
		if (y==fa) continue;
		dfs1(y,x);
		up[x]+=up[y]; dn[x]+=dn[y];
	}
	if (up[x] && dn[x]) {
		fuck=1;
	}
}
int main(){
	n=read(); m=read(); q=read();
	F(i,2,n) lg[i]=lg[i>>1]+1;
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
		id[x].pb(i); id[y].pb(i);
	}
	F(i,1,n){
		if (!dfn[i]) tarjan(i,0);
//		cout<<col[i]<<"   yy\n";
	}
	F(i,1,n){
		F(j,0,SZ(v[i])){
			int x=v[i][j];
			int u=col[i],v=col[x];
			if (u>v) swap(u,v);
			if (u^v && o.insert(1ll*u*n+v).second){
				b[u].pb(v); b[v].pb(u);
			}
		}
	}
	F(i,1,bcc) {
		if (!dep[i]) {
			ct++,dfs(i,0);
		}
	}
	F(i,1,q){
		int x=read(),y=read();
		x=col[x]; y=col[y];
		if (x==y) continue;
		if (tr[x]^tr[y]) fuck=1;
		int lp=lca(x,y);
		up[x]++; up[lp]--; dn[lp]--; dn[y]++; 
	}
	dfs1(1,0);
	if (fuck) puts("No");
	else puts("Yes");
	return 0;
}