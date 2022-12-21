#include<stdio.h>
#include<algorithm>
#define pi 3.1415926535
using namespace std;
int ans,ans1;
int a[100005];
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (i=n;i>=1;i--)
	{
		if (i%2==n%2)
		ans=ans+(a[i]*a[i]-a[i-1]*a[i-1]);
	}
	printf("%.8lf",ans*pi);
}