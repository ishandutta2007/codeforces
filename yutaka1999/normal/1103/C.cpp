#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <map>
#define SIZE 500005

using namespace std;

vector <int> vec[SIZE];
int dep[SIZE],par[SIZE];
bool leaf[SIZE],use[SIZE];

void dfs(int v=0,int p=-1,int d=0)
{
	use[v]=true;
	dep[v]=d;
	par[v]=p;
	leaf[v]=true;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			if(!use[to])
			{
				leaf[v]=false;
				dfs(to,v,d+1);
			}
		}
	}
}
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	int sz=(n+k-1)/k;
	for(int i=0;i<n;i++)
	{
		if(dep[i]+1>=sz)
		{
			vector <int> vec;
			int now=i;
			while(now!=-1)
			{
				vec.push_back(now);
				now=par[now];
			}
			puts("PATH");
			printf("%d\n",vec.size());
			for(int j=0;j<vec.size();j++) printf("%d ",vec[j]+1);puts("");
			return 0;
		}
	}
	puts("CYCLES");
	int zan=k;
	for(int i=0;i<n;i++)
	{
		if(leaf[i]&&zan>0)
		{
			zan--;
			vector <int> vx;
			bool up=false;
			for(int a=0;a<vec[i].size();a++)
			{
				for(int b=a+1;b<vec[i].size();b++)
				{
					int s=vec[i][a],t=vec[i][b];
					if(dep[s]>dep[t]) swap(s,t);//dep[s]<=dep[t]
					if((dep[t]-dep[s]+2)%3!=0)
					{
						vx.push_back(i);
						vx.push_back(t);
						int now=t;
						while(now!=s)
						{
							now=par[now];
							vx.push_back(now);
						}
						up=true;
						break;
					}
				}
				if(up) break;
			}
			printf("%d\n",vx.size());
			for(int j=0;j<vx.size();j++) printf("%d ",vx[j]+1);
			puts("");
		}
	}
	return 0;
}