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
int n,a[101000]={},b[101000]={};
char c1[101000]={},c2[101000]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n/2;++i)
		c1[i]=c2[i]='1';
	for(int i=n/2+1;i<=n;++i)
		c1[i]=c2[i]='0';
}
int get(int v,int *p)
{
	int l=0,r=n;
	while(l!=r)
	{
		int mid=l+r+1>>1;
		if(v>=p[mid])
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
void work()
{
	for(int i=n/2+1;i<=n;++i)
	{
		int pos=get(a[i],b);
		if(pos+i<=n)
			c1[i]='1';
		else
			break;
	}
	for(int i=n/2+1;i<=n;++i)
	{
		int pos=get(b[i],a);
		if(pos+i<=n)
			c2[i]='1';
		else
			break;
	}
	puts(c1+1);
	puts(c2+1);
}
int main()
{	
	init();
	work();
	return 0;
}