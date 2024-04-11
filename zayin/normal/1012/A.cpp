#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL; 

int n;
int a[maxn];

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<2*n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n+n);
	LL ans=(LL)(a[2*n-1]-a[n])*(a[n-1]-a[0]);
	for (int i=1;i<n;++i)
		ans=min(ans,(LL)(a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
	for (int i=1;i<n;++i)
		ans=min(ans,(LL)(a[2*n-1]-a[i])*(a[n]-a[0]));
	printf("%I64d\n",ans);
	return 0;
}