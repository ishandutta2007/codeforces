#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<map>
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
namespace graph
{
	int h[N];
	int v[2*N];
	int t[2*N];
	int cnt;
	void add(int x,int y)
	{
		cnt++;
		v[cnt]=y;
		t[cnt]=h[x];
		h[x]=cnt;
	}
}
std::map<int,int> s;
vector<int> g[N];
int ans;
int f[N];
int k;
int e[N];
int ff[N];
int ti;
void dfs1(int x,int fa)
{
	e[++ti]=x;
	ff[x]=fa;
	for(int i=graph::h[x];i;i=graph::t[i])
	{
		int v=graph::v[i];
		if(v!=fa)
			dfs1(v,x);
	}
}
void dfs(int x,int fa)
{
	int s1=0,s2=0;
	for(int i=graph::h[x];i;i=graph::t[i])
	{
		int v=graph::v[i];
		if(v!=fa)
		{
//			dfs(v,x);
			if(f[v]>s1)
			{
				s2=s1;
				s1=f[v];
			}
			else if(f[v]>s2)
				s2=f[v];
		}
	}
	if(s1+s2+1>=k)
	{
		ans++;
		f[x]=0;
	}
	else
		f[x]=s1+1;
}
int n;
int get(int x)
{
	if(s.count(x))
		return s[x];
	k=x;
	ans=0;
//	dfs(1,0);
	for(int i=n;i>=1;i--)
		dfs(e[i],ff[e[i]]);
	return s[x]=ans;
}
int main()
{
	open("cf1039d");
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++)
	{
		x=rd();
		y=rd();
		graph::add(x,y);
		graph::add(y,x);
	}
	dfs1(1,0);
	int i;
	for(i=1;i*i<=n;i++)
		printf("%d\n",get(i));
	for(;i<=n;)
	{
		int now=get(i);
		int l=i,r=(now?n/now:n);
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(get(mid)==now)
				l=mid;
			else
				r=mid-1;
		}
		for(int j=i;j<=l;j++)
			printf("%d\n",now);
		i=l+1;
	}
	return 0;
}