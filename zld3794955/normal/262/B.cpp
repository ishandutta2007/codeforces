#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,k,a[N]={};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n && k;++i)
		if(a[i]<0)
			a[i]=-a[i],--k;
	if(k%2==0)
		printf("%d\n",accumulate(a+1,a+n+1,0));
	else
		printf("%d\n",accumulate(a+1,a+n+1,0)-(*min_element(a+1,a+n+1))*2);
}