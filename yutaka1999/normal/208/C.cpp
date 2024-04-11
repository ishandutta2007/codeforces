#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 105
#define INF 1000000000

using namespace std;
typedef long long int ll;

struct br
{
	ll memo[SIZE];
	br operator+(br b)
	{
		br ret;
		for(int i=0;i<SIZE;i++) ret.memo[i]=memo[i]+b.memo[i];
		return ret;
	}
	ll mxe()
	{
		ll ret=0;
		for(int i=0;i<SIZE;i++) ret=max(ret,memo[i]);
		return ret;
	}
	void clear()
	{
		for(int i=0;i<SIZE;i++) memo[i]=0;
	}
	void add(int x,ll y)
	{
		memo[x]+=y;
	}
	void see()
	{
		for(int i=0;i<12;i++) printf("%d ",memo[i]);
		printf("\n");
	}
};
vector <int> vec[SIZE];
bool use[SIZE];
int time[SIZE];
ll hm[SIZE];
br b[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	fill(time,time+n,INF);
	memset(use,false,sizeof(use));
	memset(hm,0,sizeof(hm));
	queue <int> que;
	que.push(0);
	b[0].clear();use[0]=true;
	hm[0]=1;time[0]=0;
	while(!que.empty())
	{
		int v=que.front();que.pop();
		//printf("%d %d\n",time[v],hm[v]);
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(time[to]>time[v]+1)
			{
				time[to]=time[v]+1;
				use[to]=false;
				b[to].clear();
				hm[to]=0;
			}
			if(time[to]==time[v]+1)
			{
				br plus=b[v];
				plus.add(v,hm[v]);plus.add(to,hm[v]);
				b[to]=b[to]+plus;
				hm[to]+=hm[v];
				if(!use[to])
				{
					use[to]=true;
					que.push(to);
				}
			}
		}
	}
	printf("%.7f\n",(double) b[n-1].mxe()/hm[n-1]);
	return 0;
}