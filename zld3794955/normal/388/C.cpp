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
int n,s[110]={},c[110][1110]={},ans1=0,ans2=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&s[i]);
		for(int j=1;j<=s[i];++j)
			scanf("%d",&c[i][j]);
	}
}
void work()
{
	int d[110]={},t=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=s[i]/2;++j)
			ans1+=c[i][j],ans2+=c[i][s[i]+1-j];
		if(s[i]&1)
			d[++t]=c[i][(s[i]+1)/2];
	}
	sort(d+1,d+t+1);
	for(int i=t;i>=2;i-=2)
	{
		ans1+=d[i];
		ans2+=d[i-1];
	}
	if(t&1)
		ans1+=d[1];
	printf("%d %d\n",ans1,ans2);
}
int main()
{	
	init();
	work();
	return 0;
}