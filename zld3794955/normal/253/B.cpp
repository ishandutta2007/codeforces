#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N]={};
int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=1;i<=n;++i)
		ans=min(ans,n-(upper_bound(a+1,a+n+1,a[i]*2)-a-i));
	printf("%d\n",ans);
	return 0;
}