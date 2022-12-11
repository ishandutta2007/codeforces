#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
struct xxx
{
	int a[1000010][30];
	int f[1000010];
	int n;
	int q[1000010];
	int h,t;
	xxx()
	{
		n=1;
		memset(a,0,sizeof a);
	}
	int insert(char *s)
	{
		int now=1;
		int i;
		int n=strlen(s+1);
		for(i=1;i<=n;i++)
		{
			if(!a[now][s[i]-'a'+1])
				a[now][s[i]-'a'+1]=++this->n;
			now=a[now][s[i]-'a'+1];
		}
		return now;
	}
	void build()
	{
		h=0;
		t=1;
		q[++h]=1;
		f[1]=0;
		int x,i;
		while(h>=t)
		{
			x=q[t++];
			for(i=1;i<=26;i++)
				if(a[x][i])
				{
					int v=a[x][i];
					int fa=f[x];
					while(fa&&!a[fa][i])
						fa=f[fa];
					if(fa)
						f[v]=a[fa][i];
					else
						f[v]=1;
					q[++h]=v;
				}
		}
	}
};
ll c[1000010];
xxx a;
list<int> l[1000010];
int st[1000010];
int ed[1000010];
int ti;
int sz;
int b[1000010];
void dfs(int x)
{
	st[x]=++ti;
	for(auto v:l[x])
		dfs(v);
	ed[x]=ti;
}
void add(int x,ll v)
{
	for(;x<=sz;x+=x&-x)
		c[x]+=v;
}
ll sum(int x)
{
	int s=0;
	for(;x;x-=x&-x)
		s+=c[x];
	return s;
}
void add(int x,int y,int v)
{
	add(x,v);
	add(y+1,-v);
}
void inc(int x,int v)
{
	add(st[x],ed[x],v);
}
int id[1000010];
char s[1000010];
int main()
{
//	freopen("cf163e.in","r",stdin);
//	freopen("cf163e.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=k;i++)
	{
		scanf("%s",s+1);
		id[i]=a.insert(s);
	}
	a.build();
	sz=a.n;
	for(i=2;i<=sz;i++)
		l[a.f[i]].push_back(i);
	dfs(1);
	for(i=1;i<=k;i++)
	{
		inc(id[i],1);
		b[i]=1;
	}
	ll ans;
	int j,m,x;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='+')
		{
			sscanf(s+1,"%d",&x);
			if(b[x])
				continue;
			b[x]=1;
			inc(id[x],1);
		}
		else if(s[0]=='-')
		{
			sscanf(s+1,"%d",&x);
			if(!b[x])
				continue;
			b[x]=0;
			inc(id[x],-1);
		}
		else
		{
			m=strlen(s+1);
			ans=0;
			int now=1;
			for(j=1;j<=m;j++)
			{
				while(now&&!a.a[now][s[j]-'a'+1])
					now=a.f[now];
				if(!now)
					now=1;
				else
					now=a.a[now][s[j]-'a'+1];
				ans+=sum(st[now]);
			}
			printf("%I64d\n",ans);
		}
	}
	return 0;
}