#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 200005

using namespace std;

int pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);a--;
		pos[a]=i;
	}
	int r=n,cnt=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);a--;
		if(i<pos[a]+cnt)
		{
			cnt++;
			r=min(r,pos[a]);
		}
	}
	printf("%d\n",n-r);
	return 0;
}