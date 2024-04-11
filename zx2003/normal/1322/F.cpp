#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
inline void upa(int&a,const int&b){a<b?a=b:0;}
typedef vector<int>V;
int n,m;
V e[N],e2[N];
int dfn[N],dcnt,dep[N],dad[N],anc[20][N],tg[N],tg2[N];
int g[N*2];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
inline void uni(int x,int y){g[gfa(x)]=gfa(y);}
void dfs(int x,int fa){
	dfn[++dcnt]=x;dep[x]=dep[fa]+1;dad[x]=anc[0][x]=fa;
	if(fa)e[x].erase(find(e[x].begin(),e[x].end(),fa));
	for(int y:e[x])dfs(y,x);
}
void dfs2(int x,int fa){
	for(int y:e[x])dfs2(y,x),tg[x]+=tg[y],tg2[x]+=tg2[y];
	if(tg[x])uni(x,fa),uni(x+n,fa+n);
}
inline int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int dt=dep[y]-dep[x],i;for(i=0;1<<i<=dt;++i)if(dt>>i&1)y=anc[i][y];
	if(x==y)return x;
	for(i=19;i>=0;--i)if(anc[i][x]!=anc[i][y])x=anc[i][x],y=anc[i][y];
	return anc[0][x];
}
inline int climb(int x,int k){for(int i=0;1<<i<=k;++i)if(k>>i&1)x=anc[i][x];return x;}
inline void build(){
	int x,y,z,xx,yy,i,j;
	for(i=1;i<n;++i)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	for(i=1;i<20;++i)for(j=1;j<=n;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	for(i=1;i<=n*2;++i)g[i]=i;
	for(i=1;i<=m;++i){
		cin>>x>>y;xx=yy=0;
		z=lca(x,y);++tg2[x];++tg2[y];tg2[z]-=2;
		if(dep[y]>dep[z])++tg[y],--tg[yy=climb(y,dep[y]-dep[z]-1)];
		if(dep[x]>dep[z])++tg[x],--tg[xx=climb(x,dep[x]-dep[z]-1)];
		if(xx && yy)uni(xx,yy+n),uni(xx+n,yy);
	}
	dfs2(1,0);for(i=1;i<=n;++i)if(gfa(i)==gfa(i+n)){cout<<-1<<endl;exit(0);}
}
int f[N];bool rev[N];
struct seg{int l,r;};
inline seg operator&(const seg&a,const seg&b){return (seg){max(a.l,b.l),min(a.r,b.r)};}
inline seg operator|(const seg&a,const seg&b){return (seg){min(a.l,b.l),max(a.r,b.r)};}
inline bool E(const seg&a){return a.l>a.r;}
inline bool ck(int lm){
	int i,j,k,l,x,y,z;
	seg A=(seg){0,lm};
	for(i=n;i;--i){
		x=dfn[i];
		seg s=A;
		for(int y:e2[x])s=s&(gfa(y)==gfa(x)?(seg){f[y]+1,lm}:(seg){0,lm-f[y]-1}),rev[y]=gfa(y)==gfa(x+n);
		seg s1=s,s2=(seg){lm,0},s3;
		for(j=0;j<e[x].size();j=k){
			s3=A;
			y=e[x][j];
			for(k=j;k<e[x].size() && (z=e[x][k],gfa(z)==gfa(y) || gfa(z)==gfa(y+n));++k)
				s3=s3&(gfa(z)==gfa(y)?(seg){f[z]+1,lm}:(seg){0,lm-f[z]-1});
			if(E(s3))return 0;
			if(s3.l>lm-s3.l)s3=(seg){lm-s3.r,lm-s3.l};
			s1=s1&((seg){s3.l,lm-s3.l}|(seg){lm-s3.r,s3.r});
			if(s3.r<lm-s3.r)s2=s2|(seg){s3.r+1,lm-s3.r-1};
		}
		if(E(s1) || (s2.l<=s1.l && s1.r<=s2.r))return 0;
		if(s2.l<=s1.l && s1.l<=s2.r)f[x]=s2.r+1;else f[x]=s1.l;
		for(j=0;j<e[x].size();j=k){
			s3=A;
			y=e[x][j];
			for(k=j;k<e[x].size() && (z=e[x][k],gfa(z)==gfa(y) || gfa(z)==gfa(y+n));++k)
				s3=s3&(gfa(z)==gfa(y)?(seg){f[z]+1,lm}:(seg){0,lm-f[z]-1});
			bool bb=0;
			if(f[x]<s3.l || f[x]>s3.r)bb=1,s3=(seg){lm-s3.r,lm-s3.l};
			for(l=j;l<k;++l)z=e[x][l],rev[z]=(gfa(z)==gfa(y+n))^bb;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;build();
	int le=1,ri=n-1,md,i;static int w[N];for(i=2;i<=n;++i)w[i]=min(gfa(i),gfa(i+n));
	for(i=1;i<=n;++i){
		V e3;
		for(int x:e[i])if(w[i]==w[x])e2[i].push_back(x);else if(tg2[x])e3.push_back(x);
		sort(e3.begin(),e3.end(),[&](int x,int y){return w[x]<w[y];});e[i]=e3;
	}
	for(;le<ri;){
		md=le+ri>>1;
		if(!ck(md))le=md+1;else ri=md;
	}
	cout<<le+1<<'\n';
	ck(le);
	for(i=2;i<=n;++i){int x=dfn[i];rev[x]^=rev[dad[x]];}
	for(i=1;i<=n;++i)cout<<(rev[i]?le-f[i]:f[i])+1<<(i==n?'\n':' ');
	return 0;
}