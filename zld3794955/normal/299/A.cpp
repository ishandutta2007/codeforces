#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N]={};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int k=*min_element(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		if(a[i]%k)
		{
			puts("-1");
			return 0;
		}
	printf("%d\n",k);
	return 0;
}