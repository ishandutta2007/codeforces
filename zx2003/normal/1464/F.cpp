#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,I=-(1<<30);
int n,q,i,o,u,v,w,d;
vector<int>e[N];
int dad[N],sz[N],ma[N],dep[N],top[N],be[N],en[N],dfn[N],dcnt;
void dfs1(int x,int fa){
	dad[x]=fa;dep[x]=dep[fa]+1;sz[x]=1;
	for(int y:e[x])if(y!=fa){dfs1(y,x);if(sz[y]>sz[ma[x]])ma[x]=y;sz[x]+=sz[y];}
}
void dfs2(int x,int fa){
	dfn[be[x]=++dcnt]=x;if(ma[x])top[ma[x]]=top[x],dfs2(ma[x],x);
	for(int y:e[x])if(y!=fa && y!=ma[x])top[y]=y,dfs2(y,x);en[x]=dcnt;
}
inline int lca(int x,int y){
	for(;top[x]!=top[y];y=dad[top[y]])if(dep[top[x]]>dep[top[y]])swap(x,y);
	return dep[x]<dep[y]?x:y;
}
inline int ka(int x,int k){
	for(;dep[x]-dep[top[x]]+1<=k;k-=dep[x]-dep[top[x]]+1,x=dad[top[x]]);
	return dfn[be[x]-k];
}
struct segtree{
	int T[N*3],M;
	inline void ini(){for(M=1;M<n+2;M<<=1);for(i=1;i<M*2;++i)T[i]=I;}
	inline void mdy(int x,int v){for(T[x+=M]=v;x>>=1;T[x]=max(T[x<<1],T[x<<1|1]));}
	inline int ask(int l,int r){
		int ans=I;
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(!(l&1))ans=max(ans,T[l^1]);
			if(r&1)ans=max(ans,T[r^1]);
		}
		return ans;
	}
	inline int mxid(){int i=1;for(;i<M;)i=i<<1|(T[i<<1|1]==T[1]);return i-M;}
}T1,T2;
int cnt[N],tot;
inline void mdy1(int x,int v){
	cnt[x]+=v;tot+=v;
	T1.mdy(be[x],cnt[x]?dep[x]:I);
}
inline void mdy2(int x){
	for(int y=x;y;y=dad[top[y]])
		if(be[y]<en[y])T2.mdy(be[y],T1.ask(en[ma[y]]+1,en[y])-dep[y]*2);
}
struct BIT{
	int bi[N];
	inline void add(int x,int v){for(;x<=n;x+=x&-x)bi[x]+=v;}
	inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
	inline int ask(int l,int r){return ask(r)-ask(l-1);}
}b1,b2;
inline bool ck2(int x,int d){
	int y=x,lst=0;
	for(;y;y=dad[lst=top[y]]){
		if(T2.ask(be[top[y]],be[y]-1)+dep[x]>d)return 0;
		if((lst?max(T1.ask(be[y]+1,be[lst]-1),T1.ask(en[lst]+1,en[y]))+dep[x]-dep[y]*2:
			T1.ask(be[y]+1,en[y])-dep[x])>d)return 0;
	}
	return 1;
}
inline bool ck3(int x){
	int v1=b1.ask(be[x],en[x]),v2=b2.ask(be[x],en[x]);
	return tot==v1-v2;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=1;i<n;++i)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	dfs1(1,0);top[1]=1;dfs2(1,0);T1.ini();T2.ini();
	for(;q--;){
		cin>>o>>u;
		if(o<3){
			cin>>v,w=lca(u,v),o=o==1?1:-1,mdy1(w,o),mdy2(w);
			b1.add(be[u],o);b1.add(be[v],o);b2.add(be[w],o);
		}else{
			bool fl=1;d=u,u=dfn[T1.mxid()];
			if(dep[u]-dep[1]>d){
				u=ka(u,d),fl&=ck2(u,d);
				if(dep[u]-dep[1]>d)fl&=ck3(ka(u,d));
			}
			cout<<(fl?"Yes":"No")<<'\n';
		}
	}
}