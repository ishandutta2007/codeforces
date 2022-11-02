#include<bits/stdc++.h>
#define maxn 2050
#define maxm 6050
using namespace std;

int n,m;

int D,d[maxn];

int vs,vt;

int tot;
int cost[maxm];
int head[maxn],edge[maxm],nxt[maxm];

int sum;

void join(int u,int v,int c)
{
//	cout<<u<<" "<<v<<" "<<c<<endl;
	cost[tot]=c; edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
	cost[tot]=0; edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
	sum=tot=0;
	memset(head,-1,sizeof(head));
	memset(d,0,sizeof(d));
	
	scanf("%d%d%d",&n,&m,&D);
	vs=n+m+1,vt=n+m+2;
	
	for (int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		join(vs,i,1);
		join(i,u+m,1);
		join(i,v+m,1);
		++d[u],++d[v];
	}
	
	
	for (int i=1;i<=n;++i)
		if (d[i]>D)
			sum+=(d[i]-D)<<1,join(i+m,vt,(d[i]-D)<<1);
}

int gap[maxn];

int level[maxn];
int cur[maxn],prt[maxn];

int isap()
{
	memset(gap,0,sizeof(gap));
	for (int i=1;i<=vt;++i)
		cur[i]=head[i],++gap[level[i]=0];
	
	int ans=0,i=vs;
	while (level[vs]<vt)
	{
//		cout<<"i:"<<i<<" "<<level[i]<<endl; 
		if (i==vt)
		{
			for (int i=vt;i!=vs;i=edge[prt[i]^1])
				--cost[prt[i]],++cost[prt[i]^1];
			++ans;
			i=vs;
		}
		
		bool flag=0;
		for (int k=cur[i];~k;k=nxt[k])
		{
			int j=edge[k];
			if (cost[k]&&level[j]+1==level[i])
			{
				flag=1;
				cur[i]=prt[j]=k;
				i=j;
			}
		}
		
		if (flag)	continue;
		
//		cout<<"change:"<<i<<" "<<level[i]<<" "<<gap[level[i]]<<endl;
		if (--gap[level[i]]==0)	break;
		
		level[i]=vt;
		for (int k=head[i];~k;k=nxt[k])
			if (cost[k])
				level[i]=min(level[i],level[edge[k]]+1);
		++gap[level[i]];
		cur[i]=head[i];
		if (i!=vs)
			i=edge[prt[i]^1];
	}
	
	return ans;
}

vector<int> E;
int C,col[maxm];

void solve()
{
	memset(col,0,sizeof(col));
	if (isap()!=sum)
	{
		for (int i=1;i<=m;++i)
			printf("0 ");
	} else
	{
		C=1;
		for (int i=1;i<=n;++i)
		{
			if (d[i]<=D)	continue;
			
			E.clear(); 
			for (int k=head[i+m];~k;k=nxt[k])
			{
				int j=edge[k];
				if (!cost[k]||j==vt)	continue;
				E.push_back(j);
			}
			
			/*cout<<i<<":";
			for (auto e:E)
				cout<<e<<" ";
			cout<<endl;*/
			
			for (int k=0;k<E.size();k+=2)
				col[E[k]]=C,col[E[k+1]]=C,++C;
		}
		
		for (int i=1;i<=m;++i)
			if (col[i])
				printf("%d ",col[i]);
			else
				printf("%d ",C++);
	}
	puts("");
}

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		init();
		solve();
	}
	return 0;
}