#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 255
#define INF 1000000000
#define DINF 100000000000000LL

using namespace std;
typedef long long int ll;

struct MCB
{
	struct edge
	{
		int to,cap,rev;
		ll cost;
		edge(int to=-1,int cap=-1,ll cost=-1,int rev=-1):to(to),cap(cap),cost(cost),rev(rev){}
	};
	vector <edge> vec[SIZE];
	ll d[SIZE];
	int pv[SIZE],pe[SIZE];
	bool use[SIZE];
	int n;
	
	void init(int N)
	{
		n=N;
	}
	void add(int start,int end,int cap,ll cost)
	{
		int s=vec[start].size(),e=vec[end].size();
		vec[start].push_back(edge(end,cap,cost,e));
		vec[end].push_back(edge(start,0,-cost,s));
	}
	ll min_cost(int s,int t,int f)
	{
		ll flow=0;
		while(f>0)
		{
			fill(d,d+n,DINF);
			memset(use,false,sizeof(use));
			d[s]=0;
			while(1)
			{
				bool up=false;
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<vec[i].size();j++)
					{
						edge e=vec[i][j];
						if(e.cap>0&&d[e.to]>d[i]+e.cost)
						{
							d[e.to]=d[i]+e.cost;
							pv[e.to]=i;
							pe[e.to]=j;
							up=true;
						}
					}
				}
				if(!up) break;
			}
			if(d[t]>=0) return flow;
			int dt=f;
			for(int v=t;v!=s;v=pv[v]) dt=min(dt,vec[pv[v]][pe[v]].cap);
			f-=dt;
			flow+=(ll) dt*d[t];
			//printf("%d %d\n",f,flow);
			for(int v=t;v!=s;v=pv[v])
			{
				edge&e=vec[pv[v]][pe[v]];
				e.cap-=dt;
				vec[e.to][e.rev].cap+=dt;
			}
		}
		return flow;
	}
};
MCB MCF;
int A[SIZE];
int cost[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]),A[i]--;
	for(int i=0;i<n;i++) scanf("%d",&cost[i]);
	int S=n+1,T=S+1;
	MCF.init(T+2);
	MCF.add(S,0,INF,0);
	for(int i=0;i<n;i++) MCF.add(i,i+1,INF,0);
	MCF.add(n,T,INF,0);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[j]==A[i])
			{
				if(i+1<j) MCF.add(i+1,j,1,-cost[A[i]]);
				break;
			}
		}
		if(i>0&&A[i-1]==A[i]) continue;
		sum+=cost[A[i]];
		MCF.add(i,i+1,1,-DINF);
		sum+=DINF;
	}
	sum+=MCF.min_cost(S,T,k);
	printf("%lld\n",sum);
	return 0;
}