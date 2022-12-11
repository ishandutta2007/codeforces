#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
#include<queue>
#include<vector>
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
int n,m,male,female;
pii a1[10010];
pii a2[10010];
int t1[10010];
int t2[10010];
char s[110][110];
vector<int> g[10010];
int d[3010][3010];
int id(int x,int y)
{
	return (x-1)*m+y;
}
queue<int> q;
void bfs(int x)
{
	d[x][x]=0;
	q.push(x);
	int y;
	while(!q.empty())
	{
		y=q.front();
		q.pop();
		for(auto v:g[y])
			if(d[x][v]==-1)
			{
				d[x][v]=d[x][y]+1;
				q.push(v);
			}
	}
}
namespace flow
{
	int v[10000010];
	int t[10000010];
	int c[10000010];
	int h[10010];
	int cnt;
	void init()
	{
		cnt=0;
		memset(h,0,sizeof h);
	}
	void add(int x,int y,int z)
	{
		cnt++;
		v[cnt]=y;
		c[cnt]=z;
		t[cnt]=h[x];
		h[x]=cnt;
		cnt++;
		v[cnt]=x;
		c[cnt]=0;
		t[cnt]=h[y];
		h[y]=cnt;
	}
	int op(int x)
	{
		return ((x-1)^1)+1;
	}
	int d[100010];
	int e[100010];
	int num=0;
	int S,T;
	int q[100010];
	int cur[100010];
	void bfs()
	{
		memset(d,-1,sizeof d);
		int head=1,tail=0;
		q[++tail]=T;
		int x,i;
		while(tail>=head)
		{
			x=q[head++];
			e[d[x]]++;
			for(i=h[x];i;i=t[i])
				if(c[op(i)]&&d[v[i]]==-1)
				{
					d[v[i]]=d[x]+1;
					q[++tail]=v[i];
				}
		}
	}
	int dfs(int x,int flow)
	{
		if(x==T)
			return flow;
		int s=0;
		for(int &i=cur[x];i;i=t[i])
			if(c[i]&&d[v[i]]==d[x]-1)
			{
				int u=dfs(v[i],min(flow,c[i]));
				c[i]-=u;
				c[op(i)]+=u;
				flow-=u;
				s+=u;
				if(!flow)
					return s;
			}
		cur[x]=h[x];
		e[d[x]]--;
		if(!e[d[x]])
			d[S]=num;
		e[++d[x]]++;
		return s;
	}
	int maxflow()
	{
		bfs();
		if(d[S]==-1)
			return 0;
		int ans=0;
		memcpy(cur,h,sizeof h);
		while(d[S]<=num-1)
			ans+=dfs(S,0x7fffffff);
		return ans;
	}
}
int check(ll t)
{
	flow::init();
	flow::S=n*m*2+male*2+1;
	flow::T=n*m*2+male*2+2;
	flow::num=n*m*2+male*2+2;
	int i,j;
	int k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]!='#')
			{
				flow::add(id(i,j),id(i,j)+n*m,1);
				for(k=1;k<=male;k++)
				{
					if(~d[id(i,j)][id(a1[k].first,a1[k].second)]&&d[id(i,j)][id(a1[k].first,a1[k].second)]*ll(t1[k])<=t)
						flow::add(k+2*n*m,id(i,j),1);
					if(~d[id(i,j)][id(a2[k].first,a2[k].second)]&&d[id(i,j)][id(a2[k].first,a2[k].second)]*ll(t2[k])<=t)
						flow::add(id(i,j)+n*m,k+2*n*m+male,1);
				}
			}
	for(i=1;i<=male;i++)
	{
		flow::add(flow::S,i+2*n*m,1);
		flow::add(i+2*n*m+male,flow::T,1);
	}
	int s=flow::maxflow();
	return s>=male;
}
int main()
{
	memset(d,-1,sizeof d);
	open("cf513f");
	int x,y,t;
	scanf("%d%d%d%d",&n,&m,&male,&female);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]!='#')
			{
				if(i>1)
					g[id(i,j)].push_back(id(i-1,j));
				if(i<n)
					g[id(i,j)].push_back(id(i+1,j));
				if(j>1)
					g[id(i,j)].push_back(id(i,j-1));
				if(j<m)
					g[id(i,j)].push_back(id(i,j+1));
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]!='#')
				bfs(id(i,j));
	scanf("%d%d%d",&x,&y,&t);
	for(i=1;i<=male;i++)
		scanf("%d%d%d",&a1[i].first,&a1[i].second,&t1[i]);
	for(i=1;i<=female;i++)
		scanf("%d%d%d",&a2[i].first,&a2[i].second,&t2[i]);
	if(male==female-1)
	{
		male++;
		a1[male]=pii(x,y);
		t1[male]=t;
	}
	else if(male==female+1)
	{
		female++;
		a2[female]=pii(x,y);
		t2[female]=t;
	}
	else
	{
		printf("-1\n");
		return 0;
	}
	ll l=0,r=1000000000000000ll;
	if(!check(r))
	{
		printf("-1\n");
		return 0;
	}
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%I64d\n",l);
	return 0;
}