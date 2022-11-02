#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
int n,ans=0;
int s(int x)
{
	int d=x&3;
	if(d==0)	return x;
	if(d==1)	return 1;
	if(d==2)	return x+1;
	if(d==3)	return 0;
	assert(!"Shouldn't get here!");
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		ans^=x;
	}
	for(int i=1;i<=n;++i)
	{
		if(n/i%2)
			ans^=s(i-1);
		ans^=s(n%i);
	}
	printf("%d\n",ans);
}