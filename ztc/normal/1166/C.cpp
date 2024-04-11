#include<stdio.h>
#include<algorithm>
int a[200002],n;
long long cnt=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]<0?-a[i]:a[i];
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cnt+=std::upper_bound(a+i,a+n+1,a[i]<<1)-a-i-1;
	printf("%lld",cnt);
}