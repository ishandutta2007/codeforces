#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,p[N],Q,o,x,y,i,j,M;
vector<int>e[N];
int be[N],en[N],eucnt,eu[N*2],f[20][N*2],lo[N*2];
void dfs(int u){
	eu[be[u]=en[u]=++eucnt]=u;f[0][eucnt]=be[u];
	for(int v:e[u])dfs(v),eu[en[u]=++eucnt]=u,f[0][eucnt]=be[u];
}
inline int lca(int x,int y){
	x=be[x];y=be[y];if(x>y)swap(x,y);
	int l=lo[y-x+1];return eu[min(f[l][x],f[l][y-(1<<l)+1])];
}
inline bool in(int x,int y){return be[x]<=be[y] && en[y]<=en[x];}
inline bool on(int x,int y,int z){return in(x,z) && in(z,y);}
struct chain{
	int x,y;
	inline void ins(int z){
		if(!x){x=y=z;return;}
		if(x==-1)return;
		if(x==y){x=z;return;}
		int l=lca(x,y);
		if(on(l,x,z) || on(l,y,z))return;
		if(l==y)swap(x,y);
		if(l==x){
			if(!in(x,z) || lca(y,z)==x)x=z;
				else if(in(y,z))y=z;else x=-1;
		}else{
			if(in(x,z))x=z;else if(in(y,z))y=z;else x=-1;
		}
	}
}t[N*3];
inline chain uni(chain a,const chain&b){
	if(b.x==-1)a.x=-1;else if(b.x)a.ins(b.x),a.ins(b.y);
	return a;
}
inline void upd(int i){t[i]=uni(t[i<<1],t[i<<1|1]);}
int main(){
	for(i=2;i<N*2;++i)lo[i]=lo[i>>1]+1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",p+i);
	for(i=2;i<=n;++i)scanf("%d",&x),e[x].push_back(i);
	dfs(1);
	for(i=1;1<<i<=eucnt;++i)for(j=1;j+(1<<i)-1<=eucnt;++j)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
	for(M=1;M<n+1;M<<=1);for(i=1;i<=n;++i)t[p[i]+M]=(chain){i,i};
	for(i=M-1;i;--i)upd(i);
	for(scanf("%d",&Q);Q--;){
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d",&x,&y);if(x==y)continue;
			swap(t[p[x]+M],t[p[y]+M]);swap(p[x],p[y]);
			auto mdy=[&](int x){for(;x>>=1;upd(x));};
			mdy(p[x]+M);mdy(p[y]+M);
		}else{
			chain s=(chain){0,0},ns;
			for(i=1;i<M;){
				ns=uni(t[i<<1],s);
				if(ns.x==-1)i=i<<1;else s=ns,i=i<<1|1;
			}
			printf("%d\n",min(n,i-M));
		}
	}
}