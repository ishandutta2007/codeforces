#include<ext/pb_ds/priority_queue.hpp>
#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace __gnu_pbds;
using std::vector;
inline int getint(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
int buf[100];
inline void putint(int x){
	if(!x)putchar('0');
		else{
			if(x<0)putchar('-'),x=-x;
			int xb=0;
			for(;x;x/=10)buf[++xb]=x%10;
			for(;xb;--xb)putchar(buf[xb]+48);
		}
}
const int N=200010; 
int g[N],n,m,i,ans[N],j,u,v,mi[N];
bool b[N];
int gfa(int a){
	return g[a]==a?a:g[a]=gfa(g[a]);
}
struct edge{
	int u,v,w,id;	
	bool operator<(const edge&b)const{
		return w<b.w;
	}
}e[N],*ee=e;
struct pii{
	int first,second;
	bool operator<(const pii&x) const{
		return first==x.first?second<x.second:first<x.first;
	}
	bool operator>(const pii&x)const{
		return first==x.first?second>x.second:first>x.first;
	}
}x;
pii make_pair(int a,int b){
	return (pii){a,b};
}
inline int max(int a,int b){
	return a>b?a:b;
}
inline void swap(int&a,int&b){
	int t=a;
	a=b,b=t;
}
struct tree{
	struct edge{
		int to,w,id;
	};
	vector<edge> e[N];
	struct node{
		int v,x;
	};
	vector<node> in[N];
	vector<int> out[N];
	int eid[N],f[N][20],ma[N][20],dep[N];
	priority_queue<int,std::greater<int>,pairing_heap_tag> d[N];
	priority_queue<int,std::greater<int>,pairing_heap_tag>::point_iterator b[N],a[N];
	inline void addedge(int u,int v,int w,int i){
		e[u].push_back((edge){v,w,i});
		e[v].push_back((edge){u,w,i});
	}
	void dfs1(int x,int fa,int v){
		dep[x]=dep[fa]+1;
		*f[x]=fa;
		*ma[x]=v;
		for(int i=1;i<18;++i)f[x][i]=f[f[x][i-1]][i-1],ma[x][i]=max(ma[x][i-1],ma[f[x][i-1]][i-1]);
		for(unsigned int  j=0;j<e[x].size();++j)
			if(e[x][j].to!=fa)eid[e[x][j].to]=e[x][j].id,dfs1(e[x][j].to,x,e[x][j].w);
	}
	void dfs(int x,int fa){
		unsigned int i;
		for(i=0;i<e[x].size();++i)if(e[x][i].to!=fa)dfs(e[x][i].to,x),d[x].join(d[e[x][i].to]);
		for(i=0;i<in[x].size();++i)
			if(a[in[x][i].x]==NULL)a[in[x][i].x]=d[x].push(in[x][i].v);
				else b[in[x][i].x]=d[x].push(in[x][i].v);
		for(i=0;i<out[x].size();++i)d[x].erase(a[out[x][i]]),d[x].erase(b[out[x][i]]);
		if(!d[x].empty())ans[ee[eid[x]].id]=d[x].top()-1;
	}
	pii lca(int x,int y){
		if(dep[x]>dep[y])swap(x,y);
		int t=dep[y]-dep[x],ans=0,i;
		for(i=17;i>=0;--i)if(t&(1<<i))ans=max(ans,ma[y][i]),y=f[y][i];
		if(x==y)return make_pair(ans,x);
		for(i=17;i>=0;--i)if(f[x][i]!=f[y][i])ans=max(ans,max(ma[x][i],ma[y][i])),x=f[x][i],y=f[y][i];
		return make_pair(max(ans,max(*ma[x],*ma[y])),*f[x]);
	}
}t;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)e[i].u=getint(),e[i].v=getint(),e[e[i].id=i].w=getint(),ans[i]=1<<30;
	std::sort(e+1,e+m+1);
	for(i=1;i<=n;++i)g[i]=i;
	for(i=1;i<=m;++i){
		u=gfa(e[i].u);
		v=gfa(e[i].v);
		if(u!=v){
			g[u]=v;
			--j;
			b[e[i].id]=1;
			t.addedge(e[i].u,e[i].v,e[i].w,i);
		}
	}
	t.dfs1(1,0,0);
	for(i=1;i<=m;++i)
		if(!b[e[i].id]){
			x=t.lca(e[i].u,e[i].v);
			ans[e[i].id]=x.first-1;
			t.in[e[i].u].push_back((tree::node){e[i].w,i});
			t.in[e[i].v].push_back((tree::node){e[i].w,i});
			t.out[x.second].push_back(i);
		}
	t.dfs(1,0);
	for(i=1;i<=m;++i){
		if(ans[i]==1<<30)putchar('-'),putchar('1');
			else putint(ans[i]);
		putchar(' ');
	}
	return 0;
}