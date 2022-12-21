#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[100005];
long long i,j,k,l,s,m,n;
inline long long dfs(long long l,long long r)
{
	if (l>r)
	return 0;
	if (l==r)
	return 1;
	long long yy=100000;
	for (long long i=l;i<=r;i++)
	yy=min(yy,a[i]);
	for (long long i=l;i<=r;i++)
	a[i]-=yy;
	long long last=l-1;
	for (long long i=l;i<=r;i++)
	if (!a[i])
	{
		yy+=dfs(last+1,i-1);
		last=i;
	}
	yy+=dfs(last+1,r);
	yy=min(yy,r-l+1);
	return yy;
}
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	printf("%I64d\n",dfs(1,n));
}