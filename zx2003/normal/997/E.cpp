#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll C2(const int&x){return 1ll*x*(x-1)>>1;}
const int N=120005,M=N*2;
struct segtree{
	int T[N*3],M;function<int(int,int)>uni;
	void ini(int*p,int n){int i;for(M=1;M<n+2;M<<=1);for(i=1;i<=n;++i)T[i+M]=p[i];for(i=M-1;i;--i)T[i]=uni(T[i<<1],T[i<<1|1]);}
	inline int ask(int l,int r){
		int ass=T[l+M];
		for(l+=M,r+=M+1;l^r^1;l>>=1,r>>=1){if(!(l&1))ass=uni(ass,T[l^1]);if(r&1)ass=uni(ass,T[r^1]);}
		return ass;
	}
};
struct tree{
	int fa[M],tp[M],n,vcnt;
	void build(int*p,int nn){
		n=nn;
		if(n==1)return;
		static segtree t1,t2,t3,t4;
		t3.uni=t1.uni=[&](int x,int y){return x<y?x:y;};t4.uni=t2.uni=[&](int x,int y){return x>y?x:y;};
		static int g[N],lb[N],rb[N],ip[N],aa[N],tp2[N],nw[N],nxt[N];int i;
		for(i=1;i<=n;++i)ip[p[i]]=i;t1.ini(ip,n);t2.ini(ip,n);t3.ini(p,n);t4.ini(p,n);
		for(i=1;i<n;++i){
			int x=p[i],y=p[i+1];if(x>y)swap(x,y);
			lb[i]=t1.ask(x,y);rb[i]=t2.ask(x,y)-1;
		}
		auto getsup=[&](){
			static vector<int>e[N];
			static int st[N],dfn[N],low[N],bel[N],le[N],ri[N];int w,i,dcnt=0,scnt=0;
			for(i=1,w=0;i<=n;++i){
				for(;w && rb[st[w]]<i;--w);if(w)e[st[w]].push_back(i);
				for(;w && rb[st[w]]<=rb[i];--w);st[++w]=i;
			}
			for(i=n,w=0;i;--i){
				for(;w && lb[st[w]]>i;--w);if(w)e[st[w]].push_back(i);
				for(;w && lb[st[w]]>=lb[i];--w);st[++w]=i;
			}
			w=0;
			function<void(int)>dfs=[&](int x){
				dfn[x]=low[x]=++dcnt;st[++w]=x;
				for(int y:e[x]){
					if(!dfn[y])dfs(y),low[x]=min(low[x],low[y]);
						else if(!bel[y])low[x]=min(low[x],low[y]);
				}
				if(dfn[x]==low[x]){
					++scnt;le[scnt]=N;ri[scnt]=0;
					for(;;){
						int y=st[w--];bel[y]=scnt;
						auto upd=[&](int a,int b){le[scnt]=min(le[scnt],a);ri[scnt]=max(ri[scnt],b);};
						upd(y,y);
						for(int z:e[y])if(bel[z] && bel[z]!=scnt)upd(le[bel[z]],ri[bel[z]]);
						if(y==x)break;
					}
				}
			};
			for(i=1;i<n;++i)if(!dfn[i])dfs(i);
			auto ck=[&](int l,int r){return t4.ask(l,r)-t3.ask(l,r)==r-l;};
			for(i=1;i<n;++i){
				lb[i]=le[bel[i]],rb[i]=ri[bel[i]]+1;
				tp2[i]=ck(lb[i],i) && ck(i+1,rb[i]);
			}
		};
		getsup();
//		for(i=1;i<n;++i)printf("%d %d\n",lb[i],rb[i]);
		for(i=1;i<n;++i)aa[i]=i;
		sort(aa+1,aa+n,[&](int x,int y){return rb[x]-lb[x]<rb[y]-lb[y];});
		for(i=1;i<=n;++i)g[i]=i;
		function<int(int)>gfa=[&](int x){return g[x]==x?x:g[x]=gfa(g[x]);};
		for(i=1;i<=n;++i)nw[i]=i;
		vcnt=n;
		auto hedian=[&](int y){
			tp[++vcnt]=1;int z=y;
			for(;fa[nw[z]]=vcnt,nxt[z];g[z]=z+1,z=nxt[z]);nw[z]=vcnt;
		};
		auto xidian=[&](int l,int r){
			int y=l;
			vector<int>ch;
			for(;;g[y]=y+1){
				y=gfa(y);
				if(nxt[y])hedian(y),y=gfa(y);
				ch.push_back(nw[y]);if(y==r)break;
			}
			++vcnt;tp[vcnt]=2;for(int zz:ch)fa[zz]=vcnt;nw[r]=vcnt;
		};
		for(i=1;i<n;++i){
			int x=aa[i];
			if(tp2[x]==0){
				if(gfa(lb[x])==rb[x])continue;
				xidian(lb[x],rb[x]);
			}else{
				if(gfa(lb[x])!=x)hedian(gfa(lb[x]));
				if(gfa(x+1)!=rb[x])hedian(gfa(x+1));
				nxt[x]=gfa(x+1);
			}
		}
		if(gfa(1)!=n)hedian(gfa(1));
	}
	void out(){
		for(int i=1;i<=vcnt;++i)printf("%d %d\n",fa[i],tp[i]);
	}
	int deg[M],anc[20][M],dep[M],rk[M],lb[M],rb[M];
	ll sl[M],sr[M],su[M],ssl[M];vector<int>e[M];
	void ini(){
		if(n==1)return;
		static int aa[M],mn[M];int i,j;
		memcpy(anc[0]+1,fa+1,vcnt<<2);for(i=1;i<20;++i)for(j=1;j<=vcnt;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
		for(i=1;i<=n;++i)mn[i]=i;for(;i<=vcnt;++i)mn[i]=N;
		for(i=1;i<vcnt;++i)mn[fa[i]]=min(mn[fa[i]],mn[i]);
		for(i=vcnt;i;--i)dep[i]=dep[fa[i]]+1;
		for(i=1;i<vcnt;++i)aa[i]=i;
		sort(aa+1,aa+vcnt,[&](int x,int y){return mn[x]<mn[y];});
		for(i=1;i<vcnt;++i)e[fa[aa[i]]].push_back(aa[i]);
		for(i=1;i<=vcnt;++i)deg[i]=e[i].size();
		for(i=1;i<=vcnt;++i)su[fa[i]]+=su[i]+=tp[i]==1?C2(deg[i]):1;
		function<void(int)>dfs=[&](int x){
			ll s;
			for(i=1;i<=deg[x];++i)rk[e[x][i-1]]=i;
			for(i=1,s=0;i<=deg[x];++i)sl[e[x][i-1]]=sl[x]+s+(tp[x]==1?C2(i-1):0),s+=su[e[x][i-1]];
			for(i=1,s=0;i<=deg[x];++i)sr[e[x][deg[x]-i]]=sr[x]+s+(tp[x]==1?C2(i-1):0),s+=su[e[x][deg[x]-i]];
			for(i=1,s=0;i<=deg[x];++i)ssl[e[x][i-1]]=s+=su[e[x][i-1]];
			for(int y:e[x])dfs(y);
			if(x<=n)lb[x]=rb[x]=x;else lb[x]=lb[e[x][0]],rb[x]=rb[e[x].back()];
		};
		dfs(vcnt);
	}
	ll query(int x,int y){
		if(x==y)return 1;if(x==1 && y==n)return su[vcnt];
		if(x==1)return sl[y+1];if(y==n)return sr[x-1];
		--x;++y;
		int i,dt,ox=x,oy=y;dt=abs(dep[y]-dep[x]);
		for(i=0;(1<<i)<=dt;++i)if(dt>>i&1)dep[y]>dep[x]?y=anc[i][y]:x=anc[i][x];
		for(i=19;i>=0;--i)if(anc[i][x]!=anc[i][y])x=anc[i][x],y=anc[i][y];
		ll ret=sr[ox]-sr[x]+sl[oy]-sl[y];int z=fa[x];
		if(tp[z]==1)ret+=C2(rk[y]-rk[x]-1);
		ret+=ssl[e[z][rk[y]-2]]-ssl[x];
		return ret;
	}
}t;
int n,q,p[N],i,l,r;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>p[i];
	t.build(p,n);t.ini();
	for(cin>>q;q--;){
		cin>>l>>r;
		cout<<t.query(l,r)<<'\n';
	}
	return 0;
}