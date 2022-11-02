#include<bits/stdc++.h>
using namespace std;
const int V=1010000;
int n,t[V]={},v=1000000,d=5000;
int main()
{	
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++t[x];
	}
	for(int i=0;i<=v+d;++i)
	{
		t[i+1]+=t[i]/2;
		t[i]%=2;
	}
	printf("%d\n",accumulate(t,t+v+d+1,0));
	return 0;
}