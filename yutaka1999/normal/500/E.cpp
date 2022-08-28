#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define SIZE 200005
#define INF 2000000000
#define BT 20

using namespace std;

int to[SIZE][BT],cost[SIZE][BT];
int pos[SIZE],h[SIZE];
stack <int> tp;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %d",&pos[i],&h[i]);
	for(int i=n-1;i>=0;i--)
	{
		to[i][0]=-1;
		cost[i][0]=INF;
		while(!tp.empty())
		{
			int v=tp.top();tp.pop();
			if(pos[v]<=pos[i]+h[i])
			{
				to[i][0]=to[v][0];
				cost[i][0]=cost[v][0];
			}
			else
			{
				tp.push(v);
				to[i][0]=v;
				cost[i][0]=min(cost[i][0],pos[v]-(pos[i]+h[i]));
				break;
			}
		}
		if(tp.empty())
		{
			to[i][0]=n;
			cost[i][0]=0;
		}
		tp.push(i);
	}
	for(int i=0;i<BT-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(to[j][i]==n)
			{
				to[j][i+1]=n;
				cost[j][i+1]=cost[j][i];
			}
			else
			{
				to[j][i+1]=to[to[j][i]][i];
				cost[j][i+1]=cost[j][i]+cost[to[j][i]][i];
			}
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int s,t;
		scanf("%d %d",&s,&t);
		s--;t--;
		if(to[s][0]>t)
		{
			puts("0");
			continue;
		}
		int ret=0;
		for(int j=BT-1;j>=0;j--)
		{
			if(to[s][j]>t) continue;
			ret+=cost[s][j];
			s=to[s][j];
		}
		printf("%d\n",ret);
	}
	return 0;
}