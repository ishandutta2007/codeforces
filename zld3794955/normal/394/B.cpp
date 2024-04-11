#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int p,x,a[1010000]={},ans[1010000]={};
bool check(int i)
{
	int d=0;
	a[1]=i;
	for(int i=2;i<=p+1;++i)
	{
		a[i]=a[i-1]*x+d;
		d=a[i]/10;
		a[i]%=10;
	}
	return a[p+1]==a[1] && a[p+1] && d==0;
}
int main()
{	
	scanf("%d%d",&p,&x);
	ans[p]=10;
	for(int i=x;i<=9;++i)
	{
		if(check(i))
		{
			int t=p;
			while(t>=1 && a[t]==ans[t])
				--t;
			if(a[t]<ans[t])
				for(int j=1;j<=p;++j)
					ans[j]=a[j];	
		}
	}
	if(ans[p]==10)
		puts("Impossible");
	else
		for(int j=p;j>=1;--j)
			printf("%d",ans[j]);
	return 0;
}