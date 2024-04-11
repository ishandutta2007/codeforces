#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;

int main()
{
	int n,t;
	scanf("%d %d",&n,&t);t--;
	int now=0;
	for(int i=0;i<n-1;i++)
	{
		int a;
		scanf("%d",&a);
		if(now==i)
		{
			now+=a;
			if(now==t)
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}