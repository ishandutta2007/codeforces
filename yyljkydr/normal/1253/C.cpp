#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int n,a[N],m;

ll ans,c[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i-m>0)
			c[i]=c[i-m]+a[i];
		else
			c[i]=a[i];
		ans+=c[i];
		printf("%lld ",ans);
	}
}