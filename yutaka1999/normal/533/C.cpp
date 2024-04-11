#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a+b<=max(c,d)) puts("Polycarp");
	else
	{
		for(int i=1;i<=min(c,d);i++)
		{
			int x=c-i,y=d-i;
			if(x<=a&&y<=b&&(a-x)+(b-y)<=i)
			{
				puts("Polycarp");
				return 0;
			}
		}
		puts("Vasiliy");
	}
	return 0;
}