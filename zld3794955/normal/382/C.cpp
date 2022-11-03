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
int n,a[101000]={},d[101000]={},t[101000]={},top=0,ans[101000]={};
void work()
{
	bool flag=true;
	if(n==1)
	{
		printf("-1\n");
		return;
	}
	for(int i=1;i<n;++i)
		if(d[i]!=d[1])
		{
			flag=false;
			break;
		}
	if(flag)
	{
		if(n==2 && d[1]%2==0)
			ans[++top]=a[1]+d[1]/2;
		ans[++top]=a[1]-d[1];
		ans[++top]=a[n]+d[1];
	}
	else
	{
		sort(d+1,d+n);
		int p=0;
		d[0]=-0x7fffffff;
		for(int i=1;i<n;++i)
		{
			if(d[i]!=d[i-1])
				d[++p]=d[i],t[p]=1;
			else
				++t[p];
		}
		if(p>2 || d[2]!=d[1]*2 || t[2]!=1)
			top=0;
		else
		{
			int delta=d[2];
			for(int i=1;i<n;++i)
				if(a[i+1]-a[i]==delta)
				{
					ans[++top]=a[i]+delta/2;
					break;
				}
		}
	}
	sort(ans+1,ans+top+1);
	top=unique(ans+1,ans+top+1)-ans-1;
	printf("%d\n",top);
	for(int i=1;i<=top;++i)
		printf("%d ",ans[i]);
	if(top)
		puts("");
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i)
		d[i]=a[i+1]-a[i];
	work();
	return 0;
}