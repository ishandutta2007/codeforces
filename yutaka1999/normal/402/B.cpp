#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005
#define MX 1000

using namespace std;

int in[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int mx=-1,pos=-1;
	for(int i=1;i<=MX;i++)
	{
		int now=i,cnt=0;
		for(int j=0;j<n;j++)
		{
			if(now==in[j]) cnt++;
			now+=k;
		}
		if(cnt>mx)
		{
			mx=cnt;
			pos=i;
		}
	}
	printf("%d\n",n-mx);
	int now=pos;
	for(int i=0;i<n;i++)
	{
		if(now!=in[i])
		{
			if(now<in[i]) printf("- %d %d\n",i+1,in[i]-now);
			else printf("+ %d %d\n",i+1,now-in[i]);
		}
		now+=k;
	}
	return 0;
}