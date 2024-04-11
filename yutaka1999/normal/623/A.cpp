#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 505

using namespace std;

bool use[SIZE][SIZE];
vector <int> vec[SIZE];
int col[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		use[a][b]=use[b][a]=true;
	}
	memset(col,-1,sizeof(col));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j&&!use[i][j])
			{
				vec[i].push_back(j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(vec[i].size()>0)
		{
			col[i]=0;
			queue <int> que;
			que.push(i);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				for(int j=0;j<vec[v].size();j++)
				{
					int to=vec[v][j];
					if(col[to]==-1)
					{
						col[to]=col[v]^1;
						que.push(to);
					}
				}
			}
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(use[i][j]&&col[i]!=-1&&col[j]!=-1&&col[i]!=col[j])
			{
				puts("No");
				return 0;
			}
			else if(!use[i][j]&&(col[i]==-1||col[j]==-1||col[i]==col[j]))
			{
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	for(int i=0;i<n;i++)
	{
		if(col[i]==0) printf("a");
		else if(col[i]==1) printf("c");
		else printf("b");
	}puts("");
	return 0;
}