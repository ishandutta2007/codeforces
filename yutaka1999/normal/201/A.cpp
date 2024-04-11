#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int x;
	scanf("%d",&x);
	if(x==3)
	{
		printf("%d\n",5);
		return 0;
	}
	for(int i=1;;i++)
	{
		int cnt=0;
		for(int s=0,e=i-1;s<=e;s++,e--)
		{
			if(s+1==e) break;
			if(s%2==0) cnt+=(i+1)/2*(s==e?1:2);
			else cnt+=i/2*(s==e?1:2);
		}
		if(cnt>=x)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}