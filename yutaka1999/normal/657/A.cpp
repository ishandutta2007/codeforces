#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;

int main()
{
	int n,d,h;
	scanf("%d %d %d",&n,&d,&h);
	if((d==1&&n>2)||h*2<d) puts("-1");
	else
	{
		d-=h;
		int sz=2,bef=1;
		for(int i=1;i<=h;i++)
		{
			printf("%d %d\n",bef,sz);
			bef=sz++;
		}
		bef=1;
		for(int i=1;i<=d;i++)
		{
			printf("%d %d\n",bef,sz);
			bef=sz++;
		}
		while(sz<=n) {printf("%d %d\n",(h==1?1:2),sz++);}
	}
	return 0;
}