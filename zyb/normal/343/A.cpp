#include<stdio.h>
#include<algorithm>
using namespace std;
long long ans=0,n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	while (m)
	{
		ans=ans+n/m;
		n=n%m;
		swap(n,m);
	}
	printf("%I64d\n",ans);
}