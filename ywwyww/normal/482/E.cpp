#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int o[100010];
int a[100010][2];
ll p[100010];
ll g[100010];
ll h[100010];
ll s[100010];
int f[100010];
ll t[100010];
ll ans;
ll tot;
ll v[100010];
int root(int x)
{
	return !f[x]||(a[f[x]][0]!=x&&a[f[x]][1]!=x);
}
void add(int x,ll tag)
{
	t[x]+=tag;
	g[x]+=tag;
	p[x]+=2*h[x]*tag;
}
void maintain(int x)
{
	s[x]=s[a[x][0]]+s[a[x][1]]+h[x]*v[x];
}
void push(int x)
{
	if(t[x])
	{
		if(a[x][0])
			add(a[x][0],t[x]);
		if(a[x][1])
			add(a[x][1],t[x]);
		t[x]=0;
	}
}
void rotate(int x)
{
	if(root(x))
		return;
	int p=f[x];
	int q=f[p];
	int ps=(x==a[p][1]);
	int qs=(p==a[q][1]);
	int ch=a[x][ps^1];
	if(!root(p))
		a[q][qs]=x;
	if(ch)
		f[ch]=p;
	f[x]=q;
	f[p]=x;
	a[x][ps^1]=p;
	a[p][ps]=ch;
	if(ch)
		maintain(ch);
	maintain(p);
	maintain(x);
}
int st[100010];
int top;
void splay(int x)
{
	top=0;
	int y=x;
	st[++top]=y;
	while(!root(y))
	{
		y=f[y];
		st[++top]=y;
	}
	while(top)
		push(st[top--]);
	while(!root(x))
	{
		int p=f[x];
		if(root(p))
			rotate(x);
		else
		{
			int q=f[p];
			if((x==a[p][1])==(p==a[q][1]))
			{
				rotate(p);
				rotate(x);
			}
			else
			{
				rotate(x);
				rotate(x);
			}
		}
	}
	maintain(x);
}
int access(int x)
{
	int fir=x;
	int y=0;
	while(x)
	{
		if(y)
		{
			while(a[y][0])
				y=a[y][0];
			splay(y);
		}
		splay(x);
		a[x][1]=y;
		h[x]=g[x]-g[y];
		maintain(x);
		y=x;
		x=f[x];
	}
	splay(fir);
	return y;
}
list<int> l[100010];
void dfs(int x)
{
	p[x]=1;
	g[x]=1;
	for(auto v:l[x])
	{
		dfs(v);
		p[x]+=2*g[x]*g[v];
		g[x]+=g[v];
	}
	h[x]=g[x];
	ans+=p[x]*v[x];
	maintain(x);
}
int main()
{
	memset(f,0,sizeof f);
	memset(a,0,sizeof a);
	memset(s,0,sizeof s);
	int n,i;
	scanf("%d",&n);
	tot=ll(n)*n;
	o[1]=0;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&o[i]);
		f[i]=o[i];
		l[o[i]].push_back(i);
	}
	for(i=1;i<=n;i++)
		scanf("%I64d",&v[i]);
	ans=0;
	dfs(1);
	int m;
	scanf("%d",&m);
	int x,y;
	printf("%.10lf\n",double(ans)/tot);
	char str[5];
	for(i=1;i<=m;i++)
	{
		scanf("%s%d%d",str,&x,&y);
		if(str[0]=='P')
		{
			access(y);
			splay(x);
			if(!f[x])
				swap(x,y);
			access(x);
			int ff=a[x][0];
//			cut(ff,x);
			ans-=2*s[ff]*g[x];
			add(ff,-g[x]);
			f[a[x][0]]=0;
			a[x][0]=0;
			maintain(x);
			maintain(ff);
			o[x]=y;
			access(y);
			ans+=2*s[y]*g[x];
			add(y,g[x]);
			maintain(y);
//			link(y,x);
			f[x]=y;
			access(x);
		}
		else
		{
			access(x);
			ans+=p[x]*(y-v[x]);
			v[x]=y;
			access(x);
		}
		printf("%.10lf\n",double(ans)/tot);
	}
	return 0;
}