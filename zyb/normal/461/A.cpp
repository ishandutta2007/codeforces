#include<stdio.h>
#include<algorithm>
using namespace std;
long long n,a[300005],ans,i,j,k,l,s;
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	j=n;
	ans+=(j*a[n]);
	for (i=n-1;i;i--)
	{
		ans+=(j*a[i]);
		j--;
	}
	printf("%I64d\n",ans);
}