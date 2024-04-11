#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long n,q,x,y;
int main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&y,&x);
		if((x+y)&1)printf("%lld\n",n*n+1-((n-y)>>1)*n-((((n-y)&1)*n+n-x+2)>>1));	
		else printf("%lld\n",((y-1)>>1)*n+((((y-1)&1)*n+x+1)>>1));
	}
}