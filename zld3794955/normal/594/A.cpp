#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,a[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int t=n-n/2+1,ans=1<<30;
	for(int i=1;i<=n-t+1;++i)
		ans=min(a[i+t-1]-a[i],ans);
	printf("%d\n",ans);
	return 0;
}