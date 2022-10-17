#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,INF=0x7fffffff;

int n,m,k,to[N],mx[N],d[N],smx[N];

vector<int>g[N];

struct node{
	int id;
	int x,y;
}a[N];

bool cmp(node a,node b)
{
	return a.x>b.x;
}

queue<int>q;

void BFS(int S)
{
	for(int i=1;i<=n;i++)
		d[i]=-1;
	d[S]=0;
	q.push(S);
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int j=0;j<g[i].size();j++)
		{
			int v=g[i][j];
			if(d[v]==-1)
				d[v]=d[i]+1,q.push(v);
		}
	}
}

bool chk(int w)
{
	for(int i=1;i<=k;i++)
	{
		int r=w-1-a[i].y;
		if(r<0)
		r=0;
		int x=to[r];
		int val;
		if(x>=i&&mx[x]==a[i].y)
			val=smx[x];
		else
			val=mx[x];
		if(val>=w-1-a[i].x)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i].id);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	BFS(1);
	for(int i=1;i<=k;i++)
		a[i].x=d[a[i].id];
	int r=d[n]+1,l=1;
	BFS(n);
	for(int i=1;i<=k;i++)
		a[i].y=d[a[i].id];
	sort(a+1,a+k+1,cmp);
	mx[0]=smx[0]=-n*2;
	for(int i=1;i<=k;i++)
	{
		mx[i]=mx[i-1];
		smx[i]=smx[i-1];
		if(a[i].y>mx[i])
			smx[i]=mx[i],mx[i]=a[i].y;
		else if(a[i].y>smx[i])
			smx[i]=a[i].y;
	}
	int j=1;
	for(int i=a[1].x;i>=0;i--)
	{
		while(a[j+1].x>=i&&j+1<=k)
			j++;
		to[i]=j;
	}
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(chk(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d\n",l);
}
/*
maximize  min{x_i+y_j+1,x_j+y_i+1}  x<=w-y-1

5 4 2
1 2
1 2
2 3
3 4
4 5
*/