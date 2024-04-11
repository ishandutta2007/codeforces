#include<cstdio>
using namespace std;
int a[105],i,n,m,s,t;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	a[i]=(a[i]-1)/m+1;
	s=0;
	for (i=1;i<=n;i++)
	if (a[i]>=s)
	{
		t=i;
		s=a[i];
	}
	printf("%d\n",t);
}