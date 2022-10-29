#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int x,y,a,b;scanf("%d%d%d%d",&x,&y,&a,&b);
		if((y-x)%(a+b)==0)printf("%d\n",(y-x)/(a+b));
		else puts("-1");
	}
	return 0;
}