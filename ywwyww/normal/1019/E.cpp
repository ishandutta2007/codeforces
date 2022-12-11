#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=100010;
const ll inf=0x3fffffffffffffffll;
int n,m;
int f[N];
int nodecnt;
struct edge
{
	int v,a,b;
	bool used;
	edge(int _v=0,int _a=0,int _b=0):v(_v),a(_a),b(_b),used(0){}
};
vector<edge> g1[N];
void dfs1(int x,int fa)
{
	f[x]=fa;
	for(auto v:g1[x])
		if(v.v!=fa)
			dfs1(v.v,x);
}
int lastnode[N];
vector<edge> g[2*N];

//???
struct info
{
	ll x,y;
	info(ll _x=0,ll _y=0):x(_x),y(_y){}
	ll val(int t)
	{
		return x*t+y;
	}
};
info operator +(info a,info b){return info(a.x+b.x,a.y+b.y);}
info operator -(info a,info b){return info(a.x-b.x,a.y-b.y);}
ll cross(info a,info b){return a.x*b.y-a.y*b.x;}
info a1[N];
int cnt1;
int cmp(info a,info b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
int lx[N],ly[N],la[N],lb[N];
int op(int x)
{
	return ((x-1)^1)+1;
}
int d[2*N];
vector<pll> dist[2*N];
int cnt;
int c1[2*N];
int c2[2*N];
pii c3[2*N];
int sz[2*N];
int cf[2*N];
int cc[2*N];
vector<info> c[4*N],temp,temp2;
int now[4*N];
int num;
int mx;
void dfs3(int x,int fa)
{
	sz[x]=1;
	for(auto v:g[x])
		if(v.v!=fa&&!v.used)
		{
			dfs3(v.v,x);
			sz[x]+=sz[v.v];
		}
}
void dfs4(int x,int fa)
{
	for(auto v:g[x])
		if(v.v!=fa&&!v.used)
		{
			dfs4(v.v,x);
			if(max(sz[v.v],num-sz[v.v])<mx)
			{
				mx=max(sz[v.v],num-sz[v.v]);
				c1[cnt]=x;
				c2[cnt]=v.v;
			}
		}
}
void dfs5(int x,int fa,ll v1,ll v2)
{
	if(x<=n)
	{
		dist[x].push_back(pll(v1,v2));
		temp.push_back(info(v1,v2));
	}
	for(auto v:g[x])
		if(v.v!=fa&&!v.used)
			dfs5(v.v,x,v1+v.a,v2+v.b);
}
void build(int ti)
{
	static info a[N];
	int top=0;
	sort(temp.begin(),temp.end(),cmp);
	int len=temp.size();
	for(int i=0;i<len;i++)
	{
		while(top>=2&&cross(temp[i]-a[top],a[top]-a[top-1])<=0)
			top--;
		while(top>=1&&a[top].x==temp[i].x)
			top--;
		while(top>=1&&a[top].y<=temp[i].y)
			top--;
		a[++top]=temp[i];
	}
	for(int i=1;i<=top;i++)
		c[ti].push_back(a[i]);
	temp.clear();
}
void build2(int ti)
{
	static info a[N];
	int top=0;
	sort(temp2.begin(),temp2.end(),cmp);
	int len=temp2.size();
	for(int i=0;i<len;i++)
	{
		while(top>=2&&cross(temp2[i]-a[top],a[top]-a[top-1])<=0)
			top--;
		while(top>=1&&a[top].x==temp2[i].x)
			top--;
		while(top>=1&&a[top].y<=temp2[i].y)
			top--;
		a[++top]=temp2[i];
	}
	for(int i=1;i<=top;i++)
		c[ti].push_back(a[i]);
	temp2.clear();
}
void divide(int x,int fa)
{
	dfs3(x,0);
	num=sz[x];
	if(num==1)
	{
		cc[x]=fa;
		return;
	}
	mx=0x7fffffff;
	cnt++;
	dfs4(x,0);
	for(auto &v:g[c1[cnt]])
		if(v.v==c2[cnt])
		{
			v.used=1;
			c3[cnt].first=v.a;
			c3[cnt].second=v.b;
		}
	for(auto &v:g[c2[cnt]])
		if(v.v==c1[cnt])
			v.used=1;
	cf[cnt]=fa;
	dfs5(c1[cnt],0,0,0);
	build(2*cnt-1);
	dfs5(c2[cnt],0,0,0);
	build(2*cnt);
	while(1)
	{
		if(now[2*cnt-1]>=(int)c[2*cnt-1].size()||now[2*cnt]>=(int)c[2*cnt].size())
			break;
		temp2.push_back(c[2*cnt-1][now[2*cnt-1]]+c[2*cnt][now[2*cnt]]+info(c3[cnt].first,c3[cnt].second));
//		fprintf(stderr,"%lld %lld %lld %lld\n",c[2*cnt-1][now[2*cnt-1]].x,c[2*cnt-1][now[2*cnt-1]].y,c[2*cnt][now[2*cnt]].x,c[2*cnt][now[2*cnt]].y);
		ll _1=(now[2*cnt-1]==(int)c[2*cnt-1].size()-1?inf:(c[2*cnt-1][now[2*cnt-1]].y-c[2*cnt-1][now[2*cnt-1]+1].y+c[2*cnt-1][now[2*cnt-1]+1].x-c[2*cnt-1][now[2*cnt-1]].x-1)/(c[2*cnt-1][now[2*cnt-1]+1].x-c[2*cnt-1][now[2*cnt-1]].x));
		ll _2=(now[2*cnt]==(int)c[2*cnt].size()-1?inf:(c[2*cnt][now[2*cnt]].y-c[2*cnt][now[2*cnt]+1].y+c[2*cnt][now[2*cnt]+1].x-c[2*cnt][now[2*cnt]].x-1)/(c[2*cnt][now[2*cnt]+1].x-c[2*cnt][now[2*cnt]].x));
		if(_1<_2)
			now[2*cnt-1]++;
		else
			now[2*cnt]++;
	}
	int cur=cnt;
	divide(c1[cur],2*cur-1);
	divide(c2[cur],2*cur);
}
ll query(int t)
{
	while(now[0]<(int)c[0].size()-1&&c[0][now[0]+1].val(t)>=c[0][now[0]].val(t))
		now[0]++;
//	fprintf(stderr,"%lld %lld\n",c[0][now[0]].x,c[0][now[0]].y);
	return c[0][now[0]].val(t);
}
int main()
{
//	open("raining");
//	freopen("raining.in","r",stdin);
//	freopen("raining2.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		for(int i=1;i<=m;i++)
			printf("0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d%d",&lx[i],&ly[i],&la[i],&lb[i]);
		g1[lx[i]].push_back(ly[i]);
		g1[ly[i]].push_back(lx[i]);
	}
	dfs1(1,0);
	nodecnt=n;
	for(int i=1;i<=n;i++)
		lastnode[i]=i;
	for(int i=1;i<n;i++)
	{
		if(f[ly[i]]==lx[i])
			swap(lx[i],ly[i]);
		nodecnt++;
		g[nodecnt].push_back(edge(lastnode[ly[i]],0,0));
		g[lastnode[ly[i]]].push_back(edge(nodecnt,0,0));
		lastnode[ly[i]]=nodecnt;
		g[nodecnt].push_back(edge(lx[i],la[i],lb[i]));
		g[lx[i]].push_back(edge(nodecnt,la[i],lb[i]));
	}
	divide(1,0);
	build2(0);
	for(int i=0;i<m;i++)
	{
		ll ans=query(i);
		printf("%I64d\n",ans);
	}
	return 0;
}