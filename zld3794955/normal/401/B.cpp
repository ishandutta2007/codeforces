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
struct hehe
{
	int type,a,b;
}t[4040]={};
int n,k;
bool cmp(hehe r1,hehe r2)
{
	return r1.a<r2.a;
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
	{	
		scanf("%d",&t[i].type);
		if(t[i].type==1)
			scanf("%d%d",&t[i].a,&t[i].b);
		else
		{	
			scanf("%d",&t[i].a);
			t[i].b=t[i].a;
		}
	}
	++k;
	t[0].type=2;
	t[0].a=t[0].b=0;
	t[k].type=2;
	t[k].a=n;
	sort(t,t+k+1,cmp);
}
void work()
{
	int m1=0,m2=0;
	for(int i=1;i<=k;++i)
	{
		int d=t[i].a-t[i-1].b-1;
		m1+=(d+1)/2;
		m2+=d;
	}
	printf("%d %d\n",m1,m2);
}
int main()
{	
	init();
	work();
	return 0;
}