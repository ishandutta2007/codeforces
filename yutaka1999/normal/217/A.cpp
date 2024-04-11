#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct point
{
	int x,y;
};
point in[105];
bool use[105];
int n;

void flood(int v)
{
	use[v]=true;
	for(int i=0;i<n;i++)
	{
		if((in[i].x==in[v].x||in[i].y==in[v].y)&&!use[i])
		{
			flood(i);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %d",&in[i].x,&in[i].y);
	memset(use,false,sizeof(use));
	int ret=-1;
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			ret++;
			flood(i);
		}
	}
	printf("%d\n",ret);
	return 0;
}