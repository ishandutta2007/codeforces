#include<stdio.h>
#include<algorithm>
using namespace std;
int x1,x2,y1,y2;
int main()
{
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if (x1==x2&&y1==y2)
	{
		printf("-1");
		return 0;
	}
	if (y1==y2)
	{
		printf("%d %d %d %d",x1,y1+(x1-x2),x2,y2+(x1-x2));
		return 0;
	}
	if (x1==x2)
	{
		printf("%d %d %d %d",x1+(y1-y2),y1,x2+(y1-y2),y2);
		return 0;
	}
	if (abs(x1-x2)==abs(y1-y2))
	{
		printf("%d %d %d %d",x1,y2,x2,y1);
		return 0;
	}
	printf("-1");
}