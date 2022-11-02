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
int n,m,a,b[101000]={},p[101000]={},t=0,s=0;
void init()
{
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int j=1;j<=m;++j)
		scanf("%d",&p[j]);
	sort(b+1,b+n+1);
	sort(p+1,p+m+1);
}
bool check(int t)
{
	int pos=0;
	long long total=0;
	for(int i=n-t+1;i<=n;++i)
	{
		++pos;
		if(b[i]<p[pos])
			total+=p[pos]-b[i];
		if(total>a)
			return false;
	}
	return true;
}
void work()
{
	if(b[n]+a<p[1])
	{
		t=0;
		return;
	}
	int l=1,r=min(n,m);
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	t=l;
}
void work_for_total()
{
	long long sum=0;
	for(int i=1;i<=t;++i)
		sum+=p[i];
	if(sum-a<0)
		printf("0\n");
	else
		cout<<sum-a<<endl;
}
int main()
{	
	init();
	work();
	printf("%d ",t);
	work_for_total();
	return 0;
}