#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=1e5+5,M=N*2;
struct P{ll x,y;}aa[N*35],a1[N],a2[N];int acnt;
P operator-(P a,P b){return (P){a.x-b.x,a.y-b.y};}
P operator+(P a,P b){return (P){a.x+b.x,a.y+b.y};}
ll getv(P a,int k){return a.x*k+a.y;}
lll cross(P a,P b){return (lll)a.x*b.y-(lll)b.x*a.y;}
void CH(P*a,int&l){
	sort(a,a+l,[&](P u,P v){return u.x<v.x;});
	static P st[N*35];int w=0,i;
	for(i=0;i<l;++i){
		if(w && st[w].x==a[i].x)a[i].y=max(st[w--].y,a[i].y);
		for(;w>1 && cross(st[w]-st[w-1],a[i]-st[w-1])>=0;--w);st[++w]=a[i];
	}
	memcpy(a,st+1,w<<4);l=w;
}
void MS(P*a,P*b,int la,int lb){
	CH(a,la);CH(b,lb);
	static P c[N];int i=0,j=0,k=0;
	c[0]=a[0]+b[0];
	for(;i+1<la || j+1<lb;++k)if(i+1<la && (j+1==lb || cross(a[i+1]-a[i],b[j+1]-b[j])<=0))
		c[k+1]=c[k]+a[i+1]-a[i],++i;else c[k+1]=c[k]+b[j+1]-b[j],++j;
	for(i=0;i<=k;++i)aa[acnt++]=c[i];
}
int n,m,u,v,a,b,i,j;
struct edge{int to,a,b,next;}e[M*2];int h[M],ecnt=1;
vector<edge>ee[N];
int sz[M],sum,ce;
bool vi[M];
void getce(int x,int fa){
	sz[x]=1;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa && !vi[i>>1]){
		getce(e[i].to,x);sz[x]+=sz[e[i].to];
		auto calc=[&](int i){return max(sum-sz[e[i].to],sz[e[i].to]);};
		if(!ce || calc(i)<calc(ce))ce=i;
	}
}
void dfs(int x,int fa,P*a,int&l,P d){
	if(x<=n)a[l++]=d;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa && !vi[i>>1])
		dfs(e[i].to,x,a,l,d+(P){e[i].a,e[i].b});
}
void solve(int x){
	if(sum==1)return;
	int rv=e[x].to,lv=e[x^1].to,l1=0,l2=0;vi[x>>1]=1;
	dfs(rv,0,a1,l1,(P){0,0});dfs(lv,0,a2,l2,(P){e[x].a,e[x].b});
	if(l1 && l2)MS(a1,a2,l1,l2);
	sum-=sz[rv];ce=0;getce(lv,0);solve(ce);
	sum=sz[rv];ce=0;getce(rv,0);solve(ce);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)scanf("%d%d%d%d",&u,&v,&a,&b),
		ee[u].push_back((edge){v,a,b}),ee[v].push_back((edge){u,a,b});
	auto addedge=[&](int u,int v,int a,int b){
		e[++ecnt]=(edge){v,a,b,h[u]};h[u]=ecnt;
		e[++ecnt]=(edge){u,a,b,h[v]};h[v]=ecnt;
	};
	int vcnt=n;
	function<void(int,int)>dfss=[&](int x,int fa){
		if(fa){for(i=0;ee[x][i].to!=fa;++i);ee[x].erase(ee[x].begin()+i);}
		for(auto u:ee[x])dfss(u.to,x);
		int z=x;
		for(i=0;i+2<ee[x].size();++i){
			addedge(z,ee[x][i].to,ee[x][i].a,ee[x][i].b);
			addedge(z,++vcnt,0,0);z=vcnt;
		}
		for(;i<ee[x].size();++i)addedge(z,ee[x][i].to,ee[x][i].a,ee[x][i].b);
	};
	dfss(1,0);
	sum=vcnt;getce(1,0);solve(ce);
	CH(aa,acnt);
	for(i=j=0;i<m;++i){
		for(;j+1<acnt && getv(aa[j+1],i)>getv(aa[j],i);++j);
		printf("%lld%c",getv(aa[j],i),i==m-1?'\n':' ');
	}
}