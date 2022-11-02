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
int n,c[303000]={};
struct s
{
	int a,num;
}b[303000]={};
bool cmp(s a,s b)
{
	return a.a<b.a;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i].a);
	for(int i=1;i<=n;++i)
		b[i].num=i;
	sort(b+1,b+n+1,cmp);
}
void work()
{
	int t=0;
	for(int i=1;i<=n;++i)
	{
		if(t>=b[i].a)
			++t;
		else
			t=b[i].a;
		c[b[i].num]=t;
	}
	for(int i=1;i<=n;++i)
		printf("%d ",c[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}