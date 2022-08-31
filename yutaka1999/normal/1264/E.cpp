#include <bits/stdc++.h>
#define SIZE 55
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

bool ans[SIZE][SIZE];
bool all[SIZE][SIZE];
vector <int> vec[SIZE];
int deg[SIZE];
bool use[SIZE];
int back[SIZE];
int n,m;
bool dfs(int v)
{
	use[v]=true;
	for(int i=0;i<n;i++)
	{
		if(ans[v][i]&&!all[v][i]&&!use[i])
		{
			if(deg[v]-1>deg[i])
			{
				swap(ans[v][i],ans[i][v]);
				deg[v]--;
				deg[i]++;
				return true;
			}
			if(deg[v]-1==deg[i])
			{
				swap(ans[v][i],ans[i][v]);
				deg[v]--;
				deg[i]++;
				if(dfs(i)) return true;
				swap(ans[v][i],ans[i][v]);
				deg[v]++;
				deg[i]--;
			}
		}
	}
	return false;
}			
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		all[a][b]=all[b][a]=true;
		ans[a][b]=true;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(!all[i][j])
			{
				ans[i][j]=true;
				vec[i].push_back(j);
				vec[j].push_back(i);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		deg[i]=0;
		for(int j=0;j<n;j++) if(ans[i][j]) deg[i]++;
	}
	int cnt=0;
	while(1)
	{
		bool up=false;
		for(int i=0;i<n;i++)
		{
			memset(use,false,sizeof(use));
			if(dfs(i)) up=true;
		}
		if(!up) break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d",ans[i][j]);
		puts("");
	}
	return 0;
}