#include<bits/stdc++.h>
using namespace std;
const int V=2002000;
int n,k,v=1000000,t[V]={},s[V]={};
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++t[x];
	}
	partial_sum(t,t+V,s);
}
void work()
{
	for(int d=v;d>=1;--d)
	{
		int sum=0;
		for(int i=d;i<=v;i+=d)
			sum+=s[i+min(d,k+1)-1]-s[i-1];
		if(sum==n)
		{
			printf("%d\n",d);
			return;
		}
	}
}
int main()
{	
	init();
	work();
	return 0;
}