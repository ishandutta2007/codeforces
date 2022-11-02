#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010;
int n,a[N]={};
int main()
{	
	cin>>n;
	if(n%4==2 || n%4==3)
		puts("-1");
	else
	{
		int l=n/2,r=n/2+1;
		if(n%4==1)
			a[(n+1)/2]=(n+1)/2,++r;
		while(l)
		{
			a[l-1]=l;
			a[l]=r+1;
			a[r]=l-1;
			a[r+1]=r;
			l-=2,r+=2;
		}
		for(int i=1;i<=n;++i)
			printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}