#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,a[200002],ans;
int main()
{
	scanf("%I64d",&n);
	for(i=1;i<=(n<<1);i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+(n<<1)+1);
	ans=(a[n]-a[1])*(a[n<<1]-a[n+1]);
	for(i=2;i<=n;i++)ans=min(ans,(a[n<<1]-a[1])*(a[i+n-1]-a[i]));
	printf("%I64d",ans);
}