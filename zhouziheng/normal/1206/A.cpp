#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n=0;scanf("%d",&n);
	int maxa=0,a=0;
	while(n--)
	{
		scanf("%d",&a);
		maxa=max(maxa,a);
	}
	printf("%d ",maxa);
	
	scanf("%d",&n);
	maxa=0;
	while(n--)
	{
		scanf("%d",&a);
		maxa=max(maxa,a);
	}
	printf("%d ",maxa);
	return 0;
}