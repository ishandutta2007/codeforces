#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,k,a[N]={},sg=0;
int mex(int x,int y)
{
	if(x>y) swap(x,y);
	return x==0 ? y==1 ? 2 : 1 : 0;
}
int calc(int now)
{
	if(now==0)
		return 0;
	if(now%2)
		return now<=3;
	else
		return mex(calc(now/2),calc(now-1));
}
int main()
{	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	if(k%2==0)
	{
		for(int i=1;i<=n;++i)
			if(a[i]<=2)
				sg^=a[i];
			else
				sg^=!(a[i]%2);
	}
	else
	{
		for(int i=1;i<=n;++i)
			sg^=calc(a[i]);
	}
	puts(sg ? "Kevin" : "Nicky");
	return 0;
}