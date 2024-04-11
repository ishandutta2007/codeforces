#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		b+=2;
		int now=0;
		for(;b>0;now++)
		{
			if(now!=0) b+=2;
			for(int i=0;i<now&&b>0;i++)
			{
				printf("%d %d\n",i+1,now+1);
				b--;
			}
		}
		int lim=now+1,pos=0;;
		for(;now<a;now++)
		{
			for(int i=0;i<2;i++)
			{
				printf("%d %d\n",now+1,pos+1);
				pos++;pos%=lim;
			}
		}
	}
	return 0;
}