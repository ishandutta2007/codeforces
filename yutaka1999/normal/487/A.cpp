#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define INF 1000000000

using namespace std;

int main()
{
	int hy,ay,dy;
	scanf("%d %d %d",&hy,&ay,&dy);
	int hm,am,dm;
	scanf("%d %d %d",&hm,&am,&dm);
	int h,a,d;
	scanf("%d %d %d",&h,&a,&d);
	int ret=INF;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			int val=i*a+j*d;
			int A=ay+i,D=dy+j;
			if(A<=dm) continue;
			if(D>=am)
			{
				ret=min(ret,val);
			}
			else
			{
				int tm=(hm+(A-dm)-1)/(A-dm);
				int damage=tm*(am-D);
				int least=max(0,damage-hy+1);
				ret=min(ret,val+least*h);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}