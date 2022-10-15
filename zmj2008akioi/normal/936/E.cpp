#include <cstdio>
#include <cstring>
#include <vector>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
const int inf=1e9,N=3e5+10;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,q,cnt,dnt,px[N],py[N],nb[N],head[N],to[N<<1],next[N<<1],fw[N][4];bool tag;
__gnu_pbds::cc_hash_table<int,__gnu_pbds::cc_hash_table<int,int>> map;
__gnu_pbds::cc_hash_table<int,__gnu_pbds::cc_hash_table<int,bool>> pv;
namespace basic{
	int lt,nw,res,dig[30];char c;
	template<typename T>T lb(T x){return x&(-x);}
	template<typename T>T min(T x,T y){return x<y?x:y;}
	template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
	template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
	int read(){
		res=0;
		for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using basic::lb;using basic::min;using basic::cmin;using basic::cmax;using basic::read;using basic::write;
struct st{
	int u,f,w;st(){};
	st(int u,int f,int w):u(u),f(f),w(w){};
};
struct pr{
	int d,f;pr(){};
	pr(int d,int f):d(d),f(f){};
};
struct bk{
	int x,l,r;bk(){};
	bk(int x,int l,int r):x(x),l(l),r(r){};
	int sz(){return r-l+1;}
	int ld(int x){return x-l+1;}
	int rd(int x){return r-x+1;}
}b[N];
template<typename T>struct queue{
	int p,q;T a[N];
	queue():p(0),q(0){};
	int size(){return q-p;}
	void push(T x){a[++q]=x;}
	T front(){return a[++p];}
	void clr(bool *c){for(int i=1;i<=q;++i)c[a[i].u]=false;p=q=0;}
};
struct trr{
	int k,*a;trr():a(NULL){};
	void recycle(){delete[] a;}
	void apply(int x){k=x+1,a=new int[x+2];for(int i=1;i<=x+1;++i)a[i]=inf;}
	void fm(int x,int d){while(x<=k)cmin(a[x],d),x+=lb(x);}
	int fq(int x){int res=inf;while(x)cmin(res,a[x]),x-=lb(x);return res;}
}f[N],g[N];
void ad(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void extend(int x,int y){
	b[++cnt].x=x,nb[map[x][y]]=cnt;int l=y,r=y;
	while(map[x].find(l-1)!=map[x].end())nb[map[x][--l]]=cnt;
	while(map[x].find(r+1)!=map[x].end())nb[map[x][++r]]=cnt;
	b[cnt].l=l,b[cnt].r=r;
}
namespace SPT{
	int a,mn,ns,p[N],sz[N];
	bool dv[N],vis[N];queue<st> q;
	std::vector<pr> vec[N];
	void dfs1(int u){
		vis[u]=true,sz[u]=b[u].sz();int w=0;
		for(int i=head[u];i;i=next[i])if(!vis[to[i]])dfs1(to[i]),sz[u]+=sz[to[i]],cmax(w,sz[to[i]]);
		vis[u]=false,cmax(w,ns-sz[u]);if(w<mn)mn=w,a=u;
	}
	void build(int u){
		int x=b[u].x,l=b[u].l,r=b[u].r;f[u].apply(r-l),g[u].apply(r-l);
		for(int w,i=l;i<=r;++i)dv[w=map[x][i]]=true,q.push(st(w,w,0));
		while(q.size()){
			st k=q.front();int v=k.u,f=k.f,d=k.w;vec[v].push_back(pr(d,f));
			for(int i=0;i<4;++i){
				int w=fw[v][i];
				if(w&&!vis[nb[w]]&&!dv[w])dv[w]=true,q.push(st(w,f,d+1));
			}
		}
		q.clr(dv);
	}
	int septrr(int u){
		int c;mn=inf,ns=sz[u],dfs1(u),c=a,dfs1(c),vis[c]=true;
		for(int i=head[c];i;i=next[i])if(!vis[to[i]])p[septrr(to[i])]=c;
		build(c),vis[c]=false;return c;
	}
	void init(){sz[1]=n,septrr(1);}
	void recycle(){for(int i=1;i<=cnt;++i)f[i].recycle(),g[i].recycle();}
	void fm(int x){
		int u=nb[x];
		for(pr dis:vec[x]){
			int d=dis.d,y=py[dis.f];
			f[u].fm(b[u].ld(y),d-y),g[u].fm(b[u].rd(y),d+y),u=p[u];
		}
	}
	int fq(int x){
		int u=nb[x],res=inf;
		for(pr dis:vec[x]){
			int d=dis.d,y=py[dis.f];
			cmin(res,min(f[u].fq(b[u].ld(y))+d+y,g[u].fq(b[u].rd(y))+d-y)),u=p[u];
		}
		return res;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)px[i]=read(),py[i]=read(),map[px[i]][py[i]]=i;
	for(auto &i:map)for(auto &j:i.second)if(!nb[j.second])extend(i.first,j.first);
	for(auto &i:map){
		if(map.find(i.first+1)==map.end())continue;
		for(auto &j:i.second){
			int w,x=i.first,y=j.first,t=map[x][y];
			if(map[x+1].find(y)==map[x+1].end())continue;w=map[x+1][y];
			if(!pv[nb[t]][nb[w]])pv[nb[t]][nb[w]]=true,ad(nb[t],nb[w]),ad(nb[w],nb[t]);
		}
	}
	for(int i=1;i<=n;++i)for(int j=0;j<4;++j)fw[i][j]=map[px[i]+dir[j][0]][py[i]+dir[j][1]];
	SPT::init(),q=read();
	for(int opt,x,y,w,i=1;i<=q;++i){
		opt=read(),x=read(),y=read(),w=map[x][y];
		if(opt==1)tag=true,SPT::fm(w);
		if(opt==2){
			if(!tag)puts("-1");
			else write(SPT::fq(w));
		}
	}
	SPT::recycle();return 0;
}