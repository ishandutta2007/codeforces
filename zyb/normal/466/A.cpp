#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,a,b;
int main()
{
	int ans=0;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if (a*m<b)
	b=a*m;
	while (n)
	{
		if (n>=m)
		{
			ans=ans+b;
			n-=m;
		}
		else
		{
			ans=ans+min(b,a*n);
			n=0;
		}
	}
	printf("%d\n",ans);
}