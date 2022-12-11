#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[100005],sum=0,hd,ans[100005];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]),sum+=a[i];
	if(sum<n||m-1+a[m]>n)
	{
		printf("-1\n");
		return 0;
	}
	hd=n;
	for(int i=1;i<=m;i++)
	{
		if(hd-a[i]+1>0)ans[i]=hd-a[i]+1;
		else
		{
			printf("-1\n");
			return 0;
		}
		hd--;sum-=a[i];
		if(i==m)break;
		while(sum<hd||m-i-1+a[m]>hd)hd--;
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}