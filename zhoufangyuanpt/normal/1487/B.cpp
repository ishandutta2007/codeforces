#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);
		if(n%2==0)printf("%d\n",(k-1)%n+1);
		else
		{
			int g=(k-1)/(n-1)%n+1,gg=(k-1)%(n-1)+1;
			if(gg<n/2+1)printf("%d\n",(g+gg-2)%n+1);
			else printf("%d\n",(g+gg-1)%n+1);
		}
	}
	return 0;
}