#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int n,num[30],ans[30];
map<int,int>id;

int main()
{
	register int i,j;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&num[i]);
		id[num[i]]=i;
	}
	sort(num+1,num+n+1);
	for(i=2;i<=n;++i)
	{
		ans[id[num[i-1]]]=num[i];
	}
	for(i=1;i<=n;++i)
	{
		ans[i]?printf("%d ",ans[i]):printf("%d ",num[1]);
	}
}