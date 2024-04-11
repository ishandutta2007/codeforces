#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int n,d;
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=2;
	for(int i=1;i<n;i++)
		if(a[i+1]-a[i]>2*d)
			ans+=2;
		else if(a[i+1]-a[i]==2*d)
			ans++;
	printf("%d\n",ans);
	return 0;
}