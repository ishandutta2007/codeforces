#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 205
#define INF 1000000000

using namespace std;

struct MaxFlow
{
	struct edge
	{
		int to,cap,rev;
		edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
	};
	vector <edge> vec[SIZE];
	int level[SIZE];
	int iter[SIZE];
	
	void init()
	{
		for(int i=0;i<SIZE;i++)
		{
			vec[i].clear();
		}
	}
	void add(int s,int t,int c)
	{
		//printf("%d %d %d\n",s,t,c);
		int S=vec[s].size(),T=vec[t].size();
		vec[s].push_back(edge(t,c,T));
		vec[t].push_back(edge(s,0,S));
	}
	void bfs(int s)
	{
		memset(level,-1,sizeof(level));
		queue <int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty())
		{
			int v = que.front();que.pop();
			for(int i=0;i<vec[v].size();i++)
			{
				edge&e=vec[v][i];
				if (e.cap>0&&level[e.to]<0)
				{
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	int flow_dfs(int v,int t,int f)
	{
		if (v==t) return f;
		for(int &i=iter[v];i<vec[v].size();i++)
		{
			edge &e=vec[v][i];
			if (e.cap>0&&level[v]<level[e.to])
			{
				int d=flow_dfs(e.to,t,min(f,e.cap));
				if (d>0)
				{
					e.cap-=d;
					vec[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s,int t)
	{
		int flow = 0;
		while(1)
		{
			bfs(s);
			if (level[t]<0) return flow;
			memset(iter,0,sizeof(iter));
			while (1)
			{
				int f=flow_dfs(s,t,INF);
				if(f==0) break;
				flow += f;
			}
		}
	}
};
MaxFlow F;
int A[SIZE],B[SIZE];
int in[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector <int> pr;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		int now=in[i];
		for(int j=2;j*j<=now;j++)
		{
			if(now%j==0)
			{
				pr.push_back(j);
				while(now%j==0) now/=j;
			}
		}
		if(now!=1) pr.push_back(now);
	}
	sort(pr.begin(),pr.end());
	pr.erase(unique(pr.begin(),pr.end()),pr.end());
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&A[i],&B[i]);
		A[i]--;B[i]--;
		if(A[i]%2==1) swap(A[i],B[i]);
	}
	int s=n,t=s+1;
	int ret=0;
	for(int j=0;j<pr.size();j++)
	{
		int p=pr[j];
		F.init();
		int mx=0;
		for(int i=0;i<n;i++)
		{
			int now=0,k=in[i];
			while(k%p==0)
			{
				now++;
				k/=p;
			}
			mx=max(mx,now);
			if(i%2==0) F.add(s,i,now);
			else F.add(i,t,now);
		}
		for(int i=0;i<m;i++) F.add(A[i],B[i],mx);
		ret+=F.max_flow(s,t);
		//printf("*%d\n",ret);
	}
	printf("%d\n",ret);
	return 0;
}