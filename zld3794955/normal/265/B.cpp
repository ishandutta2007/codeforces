#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,h[N]={};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&h[i]);
	int ans=n+n-1;
	for(int i=1;i<=n;++i)
		ans+=abs(h[i]-h[i-1]);
	printf("%d\n",ans);
}