#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#define SIZE 205
#define MX 200005
#define INF 1000000000

using namespace std;
typedef pair <int,int> P;

struct MaxFlow
{
	struct edge
	{
		int to,cap,rev,tp;
		edge(int t,int c,int r,int T)
		{
			to=t;
			cap=c;
			rev=r;
			tp=T;
		}
	};
	vector <edge> vec[SIZE];
	bool use[SIZE];
	
	void init()
	{
		for(int i=0;i<SIZE;i++) vec[i].clear();
	}
	void add(int start,int end,int cap)
	{
		int s=vec[start].size(),e=vec[end].size();
		vec[start].push_back(edge(end,cap,e,1));
		vec[end].push_back(edge(start,0,s,0));
	}
	int dfs(int v,int t,int f)
	{
		if(v==t) return f;
		use[v]=true;
		for(int i=0;i<vec[v].size();i++)
		{
			edge &e=vec[v][i];
			if(!use[e.to]&&e.cap>0)
			{
				int d=dfs(e.to,t,min(f,e.cap));
				if(d>0)
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
		int flow=0;
		while(1)
		{
			memset(use,false,sizeof(use));
			int f=dfs(s,t,INF);
			if(f==0) return flow;
			flow+=f;
		}
	}
	vector <int> used(int v)
	{
		vector <int> ret;
		for(int i=0;i<vec[v].size();i++)
		{
			edge e=vec[v][i];
			if(e.tp==1&&e.cap==0)
			{
				ret.push_back(e.to);
			}
		}
		return ret;
	}
};
bool ok[MX];
vector <P> vec[SIZE];
vector < vector <int> > V;
int A[SIZE];
bool use[SIZE];

void make()
{
	for(int i=2;i<MX;i++)
	{
		if(!ok[i])
		{
			for(int j=i*2;j<MX;j+=i) ok[j]=true;
		}
	}
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	MaxFlow F;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!ok[A[i]+A[j]])
			{
				if(A[i]%2==0)
				{
					F.add(i,j,1);
				}
			}
		}
	}
	int s=n,t=n+1;
	for(int i=0;i<n;i++)
	{
		if(A[i]%2==0)
		{
			F.add(s,i,2);
		}
		else
		{
			F.add(i,t,2);
		}
	}
	int vl=F.max_flow(s,t);
	if(vl!=n)
	{
		puts("Impossible");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(A[i]%2==0)
		{
			vector <int> ret=F.used(i);
			vec[ret[0]].push_back(P(ret[1],i));
			vec[ret[1]].push_back(P(ret[0],i));
		}
	}
	for(int i=0;i<n;i++)
	{
		if(A[i]%2==1&&!use[i])
		{
			vector <int> ans;
			int now=i,bef=-1;
			do
			{
				use[now]=true;
				ans.push_back(now);
				int nxt;
				if(vec[now][0].first==bef)
				{
					nxt=vec[now][1].first;
					ans.push_back(vec[now][1].second);
				}
				else
				{
					nxt=vec[now][0].first;
					ans.push_back(vec[now][0].second);
				}
				bef=now;
				now=nxt;
			}while(now!=i);
			V.push_back(ans);
		}
	}
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++)
	{
		vector <int> ans=V[i];
		printf("%d",ans.size());
		for(int j=0;j<ans.size();j++)
		{
			printf(" ");
			printf("%d",ans[j]+1);
		}puts("");
	}
	return 0;
}