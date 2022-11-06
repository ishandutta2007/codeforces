#include<stdio.h>
#include<queue>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
long long a[100002],n,m,k;
double maxx,h;
int main()
{
	scanf("%lld%lld%lld",&n,&k,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)a[i]+=a[i+1];
	for(long long i=1;i<=Min(n,m+1);i++)
	{
		h=Min(k*(n-i+1),m-i+1ll)+a[i];
		maxx=Max(maxx,h/double(n-i+1));
	}printf("%.7lf",maxx);
}