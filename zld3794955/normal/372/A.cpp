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
int n,a[505000]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}
bool check(int mid)
{
	int t=n;
	for(int i=mid;i;--i,--t)
		if(a[t]<a[i]+a[i])
			return false;
	return true;
}
void work()
{
	int l=0,r=n/2;
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",n-l);
}
int main()
{	
	init();
	work();
	return 0;
}