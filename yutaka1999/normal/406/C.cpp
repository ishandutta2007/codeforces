#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;

vector <int> vec[SIZE];
vector <int> back[SIZE];
int dep[SIZE],deg[SIZE],par[SIZE];
bool use[SIZE];

void dfs(int v=0,int p=-1,int d=0)
{
	use[v]=true;
	dep[v]=d;
	par[v]=p;
	deg[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(!use[to])
		{
			dfs(to,v,d+1);
			deg[v]++;
		}
		else
		{
			if(to!=p&&dep[to]<dep[v])
			{
				back[v].push_back(to);
			}
		}
	}
}
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
	if(m%2==1)
	{
		puts("No solution");
		return 0;
	}
	dfs();
	queue <int> que;
	for(int i=0;i<n;i++) if(deg[i]==0) que.push(i);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		if(back[v].size()%2==1)
		{
			for(int i=1;i<back[v].size();i+=2)
			{
				printf("%d %d %d\n",back[v][i]+1,v+1,back[v][i+1]+1);
			}
			printf("%d %d %d\n",par[v]+1,v+1,back[v][0]+1);
		}
		else
		{
			for(int i=0;i<back[v].size();i+=2)
			{
				printf("%d %d %d\n",back[v][i]+1,v+1,back[v][i+1]+1);
			}
			if(v==0) break;
			back[par[v]].push_back(v);
		}
		deg[par[v]]--;
		if(deg[par[v]]==0) que.push(par[v]);
	}
	return 0;
}