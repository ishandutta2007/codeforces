#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<queue>
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
using std::unordered_map;
using std::queue;
using std::greater;
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
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
int pri[1000000];
namespace sieve
{
	int b[1000010];
	int c[1000010];
	int cnt;
	void gao()
	{
		for(int i=2;i<=1000000;i++)
		{
			if(!b[i])
			{
				c[i]=i;
				cnt++;
				pri[cnt]=i;
			}
			for(int j=1;j<=cnt&&i*pri[j]<=1000000;j++)
			{
				b[i*pri[j]]=1;
				c[i*pri[j]]=pri[j];
				if(i%pri[j]==0)
					break;
			}
		}
	}
}
int cnt;
int cnt2;
int a[100];
int c[10000][100];
int len[10000];
int b[10000];
int e[10000];
int f[10000];
int r[10000];
int h[10000];
int f2[10000];
int ans[300][1000];
unordered_map<ull,int> s;
vector<int> g[10000];
void dfs(int x,int s,int y,int z,int h)
{
	cnt++;
	len[cnt]=x-1;
	for(int i=1;i<=x-1;i++)
		c[cnt][i]=a[i];
	f[cnt]=h;
	if(s&&s<=1000000)
	{
		b[cnt]=1;
		e[cnt]=++cnt2;
	}
	else
		s=0;
	for(int i=1,w=s*pri[x];i<=y&&i<=z;i++,w*=pri[x])
	{
		a[x]=i;
		dfs(x+1,w,i,z-i,h*(i+1));
		if(w>1000000)
			w=0;
	}
}
int d[300][10000];
queue<int> q;
void bfs(int x)
{
	memset(d[e[x]],-1,sizeof d[e[x]]);
	d[e[x]][x]=0;
	q.push(x);
	while(!q.empty())
	{
		int y=q.front();
		q.pop();
		for(auto v:g[y])
			if(d[e[x]][v]==-1)
			{
				d[e[x]][v]=d[e[x]][y]+1;
				q.push(v);
			}
	}
}
int t;
void init()
{
	sieve::gao();
	dfs(1,1,10000,22,1);
	for(int i=1;i<=cnt;i++)
	{
		ull hs=0;
		for(int j=1;j<=len[i];j++)
			hs=hs*127+c[i][j];
		s[hs]=i;
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			if(j>1&&c[i][j]==c[i][j-1])
				continue;
			for(int k=1;k<=len[i];k++)
				a[k]=c[i][k];
			a[j]++;
			sort(a+1,a+len[i]+1,greater<int>());
			ull hs=0;
			for(int k=1;k<=len[i];k++)
				hs=hs*127+a[k];
			if(s.count(hs))
			{
				g[i].push_back(s[hs]);
				g[s[hs]].push_back(i);
			}
		}
		for(int j=1;j<=len[i];j++)
			a[j+1]=c[i][j];
		a[1]=1;
		sort(a+1,a+len[i]+2,greater<int>());
		ull hs=0;
		for(int j=1;j<=len[i]+1;j++)
			hs=hs*127+a[j];
		if(s.count(hs))
		{
			g[i].push_back(s[hs]);
			g[s[hs]].push_back(i);
		}
	}
	for(int i=1;i<=cnt;i++)
		if(b[i])
			bfs(i);
	memcpy(h,f,sizeof f);
	sort(h+1,h+cnt+1);
	t=unique(h+1,h+cnt+1)-h-1;
	for(int i=1;i<=cnt;i++)
		r[i]=lower_bound(h+1,h+t+1,f[i])-h;
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=cnt;i++)
		if(b[i])
			for(int j=1;j<=cnt;j++)
				if(d[e[i]][j]!=-1)
					ans[e[i]][r[j]]=min(ans[e[i]][r[j]],d[e[i]][j]);
}
int a1[30],a2[30],c1[30],c2[30];
int t1,t2;
void solve()
{
	int x,y;
	scanf("%d%d",&x,&y);
	t1=t2=0;
	for(int i=x;i!=1;i/=sieve::c[i])
		if(t1&&sieve::c[i]==a1[t1])
			c1[t1]++;
		else
		{
			a1[++t1]=sieve::c[i];
			c1[t1]=1;
		}
	for(int i=y;i!=1;i/=sieve::c[i])
		if(t2&&sieve::c[i]==a2[t2])
			c2[t2]++;
		else
		{
			a2[++t2]=sieve::c[i];
			c2[t2]=1;
		}
	sort(c1+1,c1+t1+1,greater<int>());
	sort(c2+1,c2+t2+1,greater<int>());
	ull hs1=0,hs2=0;
	for(int i=1;i<=t1;i++)
		hs1=hs1*127+c1[i];
	for(int i=1;i<=t2;i++)
		hs2=hs2*127+c2[i];
	int x1=e[s[hs1]];
	int y1=e[s[hs2]];
	int res=0x7fffffff;
	for(int i=1;i<=t;i++)
		res=min(res,ans[x1][i]+ans[y1][i]);
	printf("%d\n",res);
}
int main()
{
	open("d");
	init();
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}