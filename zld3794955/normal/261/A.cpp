#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=100010;
int n,m,l,a[N]={};
int main()
{
	scanf("%d",&m);
	l=1<<20;
	for(int i=1,x=0;i<=m;++i)
	{
		scanf("%d",&x);
		l=min(l,x);
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int now=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		if(now<l)
			ans+=a[i];
		++now;
		if(now==l+2)
			now=0;
	}
	printf("%d\n",ans);
	return 0;
}