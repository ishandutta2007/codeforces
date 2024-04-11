#include <cstdio>
#include <vector>
#include <unordered_set>
typedef long long LL;
const int L=1,R=2e5,inf=1e9,N=2e5+10;
int n,c,sc,mn,dnt,rto,f[N],sz[N],nsz[N],rso[N],head[N],to[N],val[N],next[N];LL ans;bool vis[N];
std::vector<int> nv,son[N];std::unordered_set<int> nst,set[N];
template<typename T>T md(T x,T y){return (x+y)/2;}
template<typename T>T min(T x,T y){return x<y?x:y;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
namespace IO{
	int lt,res,dig[50];LL nw;char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(LL x,char end=' '){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);putchar(end);
	}
}using IO::read;using IO::write;
namespace VGT{
	int tnt;
	struct node{
		int l,r,sz;node():l(0),r(0),sz(0){};
		node(int l,int r,int sz):l(l),r(r),sz(sz){};
	}t[N*80];
	void pushup(int x){t[x].sz=t[t[x].l].sz+t[t[x].r].sz;}
	void modify(int l,int r,int &u,int g,int d){
		if(!u)u=++tnt;if(l==r){t[u].sz+=d;return;}
		if(md(l,r)>=g)modify(l,md(l,r),t[u].l,g,d);
		else modify(md(l,r)+1,r,t[u].r,g,d);
		pushup(u);
	}
	int query(int l,int r,int u,int v){
		if(l==r)return l;
		if(t[t[u].l].sz>t[t[v].l].sz)return query(l,md(l,r),t[u].l,t[v].l);
		else return query(md(l,r)+1,r,t[u].r,t[v].r);
	}
	void fm(int &u,int g,int d){modify(L,R,u,g,d);}
	int fq(int u,int v){return query(L,R,u,v);}
}
void ad(int u,int v,int w){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v,val[dnt]=w;}
void dfs1(int u){
	sz[u]=1;int w=0;
	for(int i=head[u];i;i=next[i]){
		if(sz[to[i]])continue;
		dfs1(to[i]),sz[u]+=sz[to[i]],cmax(w,sz[to[i]]);
		ans+=(LL)val[i]*min(sz[to[i]],n-sz[to[i]]);
	}
	cmax(w,n-sz[u]);if(w<mn)c=u,mn=w;
}
void dfs2(int u){
	vis[u]=true,nv.push_back(u);
	for(int i=head[u];i;i=next[i])if(!vis[to[i]])dfs2(to[i]);
}
void ins(std::vector<int> vec,bool tag=false){
	++sc,nsz[sc]=vec.size()<<1,set[tag?0:nsz[sc]].insert(sc);
	for(int i:vec)f[i]=sc,VGT::fm(rso[sc],i,1);
}
int main(){
	n=read();
	for(int u,v,w,i=1;i<n;++i)u=read(),v=read(),w=read(),ad(u,v,w),ad(v,u,w);
	mn=inf,dfs1(1),write(ans<<1,'\n'),ins({c},true),vis[c]=true;
	for(int i=1;i<=n;++i)VGT::fm(rto,i,1);
	for(int i=head[c];i;i=next[i])nv.clear(),dfs2(to[i]),ins(nv);
	for(int i=1;i<=n;++i){
		--nsz[f[i]],nst.clear();int u,lim=n-i+1;
		for(int j:set[lim])if(lim!=nsz[j])nst.insert(j);
		for(int j:nst)set[lim].erase(j),set[lim-1].insert(j);
		if(set[lim].size()){
			int v=*set[lim].begin();
			u=VGT::fq(rso[v],0),set[lim-1].insert(v);
		}
		else{
			u=VGT::fq(rto,rso[f[i]]);
			if(i==c&&u>c)u=c;
		}
		--nsz[f[u]],write(u);
		VGT::fm(rso[f[u]],u,-1),VGT::fm(rto,u,-1);
	}
	return 0;
}