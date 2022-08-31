#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 2005

using namespace std;

int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		in[i]=abs(in[i]);
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int a=0,b=0;
		for(int j=0;j<n;j++)
		{
			if(in[i]>in[j])
			{
				if(i>j) a++;
				else b++;
			}
		}
		ret+=min(a,b);
	}
	printf("%d\n",ret);
	return 0;
}