#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 205

using namespace std;

int in[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
	int s=2*n-1;
	for(int i=0;i<s;i++) scanf("%d",&in[i]);
	if(n%2==1)
	{
		int ret=0;
		for(int i=0;i<s;i++) ret+=abs(in[i]);
		printf("%d\n",ret);
	}
	else
	{
		sort(in,in+s);
		for(int i=0;i<s-1;i++)
		{
			if(in[i]<=0&&in[i+1]<=0)
			{
				in[i]=-in[i];
				in[i+1]=-in[i+1];
			}
		}
		sort(in,in+s);
		int sum1=0;
		for(int i=0;i<s;i++) sum1+=in[i];
		if(in[0]<0)
		{
			in[0]=-in[0];
			in[1]=-in[1];
		}
		int sum2=0;
		for(int i=0;i<s;i++) sum2+=in[i];
		printf("%d\n",max(sum1,sum2));
	}
	return 0;
}