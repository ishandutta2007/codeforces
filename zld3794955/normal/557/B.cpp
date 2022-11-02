#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=200020;
int n,w,a[N]={};
int main()
{	
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n+n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+n+1);
	double d=min(min(a[1]*1.0,a[n+1]*0.5),w/3.0/n);
	printf("%.12f\n",d*3.0*n);
	return 0;
}