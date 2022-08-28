#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 2000005

using namespace std;

int last[SIZE];
bool ok[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ok[a]=true;
	}
	int p=0;
	for(int i=0;i<SIZE;i++)
	{
		last[i]=p;
		if(ok[i]) p=i;
	}
	int ret=0;
	for(int i=0;i<SIZE;i++)
	{
		if(ok[i])
		{
			for(int j=i;j<SIZE;j+=i)
			{
				if(last[j]<i) continue;
				ret=max(ret,last[j]%i);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}