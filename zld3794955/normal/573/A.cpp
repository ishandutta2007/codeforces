#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010;
int n,a[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		while(a[i]%2==0)
			a[i]/=2;
		while(a[i]%3==0)
			a[i]/=3;
	}
	for(int i=1;i<=n;++i)
		if(a[i]!=a[1])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}