#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110;
int n,m,a,b,p[N]={},q[M]={};
int main()
{
	cin>>n>>m;
	cin>>a;
	for(int i=0,x=0;i<a;++i)
	{
		cin>>x;
		p[x]=1;
	}
	cin>>b;
	for(int i=0,x=0;i<b;++i)
	{
		cin>>x;
		q[x]=1;
	}
	int g=__gcd(n,m);
	for(int k=0;k<g;++k)
	{
		bool flag=false;
		for(int i=k;i<n;i+=g)
			flag|=p[i];
		for(int j=k;j<m;j+=g)
			flag|=q[j];
		if(!flag)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}