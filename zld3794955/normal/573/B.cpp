#include<bits/stdc++.h>
using namespace std;
const int N=100010,Inf=1<<30;
int n,h[N]={},d[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&h[i]);
	for(int i=1,tmp=0;i<=n;++i)
		tmp=max(tmp,i-h[i]),d[i]=i-tmp;
	reverse(h+1,h+n+1);
	reverse(d+1,d+n+1);
	for(int i=1,tmp=0;i<=n;++i)
		tmp=max(tmp,i-h[i]),d[i]=min(d[i],i-tmp);
	printf("%d\n",*max_element(d+1,d+n+1));
	return 0;
}