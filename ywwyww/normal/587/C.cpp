#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
struct tree
{
	int v[1000010];
	int t[1000010];
	int h[1000010];
	int n;
	tree()
	{
		n=0;
		memset(h,0,sizeof h);
	}
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
};
tree tr;
struct p
{
	int a[11];
	int n;
	p()
	{
		memset(a,0,sizeof a);
		n=0;
	}
	int& operator [](int x)
	{
		return a[x];
	}
};
p merge(p a,p b)
{
	p c;
	int i=1,j=1;
	while((i<=a.n||j<=b.n)&&c.n<10)
	{
		if(j>b.n||(i<=a.n&&a[i]<=b[j]))
			c[++c.n]=a[i++];
		else
			c[++c.n]=b[j++];
	}
	return c;
}
int f[100010][20];
p mi[100010][20];
int d[100010];
p a[100010];
void dfs(int x,int fa,int dep)
{
	d[x]=dep;
	f[x][0]=fa;
	mi[x][0]=a[x];
	int i;
	for(i=1;i<=19;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		mi[x][i]=merge(mi[x][i-1],mi[f[x][i-1]][i-1]);
	}
	for(i=tr.h[x];i;i=tr.t[i])
		if(tr.v[i]!=fa)
			dfs(tr.v[i],x,dep+1);
}
p query(int x,int y)
{
	p ans;
	if(d[x]<d[y])
		swap(x,y);
	int i;
	for(i=19;i>=0;i--)
		if(d[f[x][i]]>=d[y])
		{
			ans=merge(ans,mi[x][i]);
			x=f[x][i];
		}
	if(x==y)
		return merge(ans,mi[x][0]);
	for(i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
		{
			ans=merge(ans,merge(mi[x][i],mi[y][i]));
			x=f[x][i];
			y=f[y][i];
		}
	ans=merge(ans,merge(mi[x][0],mi[y][0]));
	x=f[x][0];
	ans=merge(ans,mi[x][0]);
	return ans;
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int x,y;
	int i,j;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		tr.add(x,y);
		tr.add(y,x);
	}
	p c;
	c.n=1;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		c.a[1]=i;
		a[x]=merge(a[x],c);
	}
	dfs(1,0,1);
	int k;
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&x,&y,&k);
		c=query(x,y);
		k=min(k,c.n);
		printf("%d ",k);
		for(j=1;j<=k;j++)
			printf("%d ",c[j]);
		printf("\n");
	}
	return 0;
}