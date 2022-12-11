#include<cstdio>
#include<algorithm>
using namespace std;
int n,b[200005],a[200005],x[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	x[1]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i]+x[i];
		x[i+1]=max(x[i],a[i]);
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
 }