#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
long long a[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%I64d",&a[i]);
	int w,h;
	scanf("%d",&m);
	long long ans=0;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&w,&h);
		ans=max(ans,a[w]);
		printf("%I64d\n",ans);
		ans+=h;
	}
	return 0;
}