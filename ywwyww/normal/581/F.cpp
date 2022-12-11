#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
struct graph
{
	int v[10010];
	int t[10010];
	int h[5010];
	int n;
	graph()
	{
		memset(h,0,sizeof h);
		n=0;
	}
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
};
graph g;
int sz[5010];
int s[5010];
int f[5010][5010];
int d[5010];
int a[5010];
int m;
void add(int x)
{
	int i;
	for(i=m;i>=x;i--)
		upmin(a[i],a[i-x]+1);
}
void dfs(int x,int fa)
{
	int c=0;
	int i,j,k;
	f[x][0]=0;
	for(i=g.h[x];i;i=g.t[i])
		if(g.v[i]!=fa)
		{
			c++;
			int v=g.v[i];
			dfs(v,x);
			memset(a,0x7f,sizeof a);
			for(j=0;j<=s[x];j++)
				for(k=0;k<=s[v];k++)
				{
					upmin(a[j+k],f[x][j]+f[v][k]);
					upmin(a[j+s[v]-k],f[x][j]+f[v][k]+1);
				}
			s[x]+=s[g.v[i]];
			for(j=0;j<=s[x];j++)
				f[x][j]=a[j];
		}
	if(!c)
	{
		s[x]=1;
		f[x][1]=0;
		f[x][0]=0x3fffffff;
	}
}
int main()
{
	open("b");
	int n;
	scanf("%d",&n);
	if(n==2)
	{
		printf("1\n");
		return 0;
	}
	int i,x,y;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		d[x]++;
		d[y]++;
		g.add(x,y);
		g.add(y,x);
	}
	int rt;
	for(i=1;i<=n;i++)
		if(d[i]!=1)
		{
			rt=i;
			break;
		}
	memset(f,0x3f,sizeof f);
	dfs(rt,0);
	int m=s[rt]/2;
	printf("%d\n",f[rt][m]);
	return 0;
}