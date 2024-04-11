#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 3005

using namespace std;

vector <int> vec[SIZE];
int dist[5][SIZE];

void make(int start,int pos)
{
	memset(dist[pos],-1,sizeof(dist[pos]));
	dist[pos][start]=0;
	queue <int> que;
	que.push(start);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(dist[pos][to]==-1)
			{
				dist[pos][to]=dist[pos][v]+1;
				que.push(to);
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
	int a1,b1,c1;
	int a2,b2,c2;
	scanf("%d %d %d",&a1,&b1,&c1);a1--;b1--;
	scanf("%d %d %d",&a2,&b2,&c2);a2--;b2--;
	make(a1,0);
	make(b1,1);
	make(a2,2);
	make(b2,3);
	int ret=dist[0][b1]+dist[2][b2];
	if(dist[0][b1]>c1||dist[2][b2]>c2)
	{
		puts("-1");
		return 0;
	}
	for(int s=0;s<n;s++)
	{
		make(s,4);
		for(int t=0;t<n;t++)
		{
			int va=dist[0][s]+dist[4][t]+dist[1][t];
			int vb=dist[2][s]+dist[4][t]+dist[3][t];
			if(va<=c1&&vb<=c2)
			{
				ret=min(ret,va+vb-dist[4][t]);
			}
			va=dist[0][s]+dist[4][t]+dist[1][t];
			vb=dist[3][s]+dist[4][t]+dist[2][t];
			if(va<=c1&&vb<=c2)
			{
				ret=min(ret,va+vb-dist[4][t]);
			}
		}
	}
	printf("%d\n",m-ret);
	return 0;
}