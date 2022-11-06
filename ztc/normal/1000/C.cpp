#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#define inf 1000000007
using namespace std;
struct node
{
	long long id,num;
	bool operator<(const node &a)const
	{
		return a.num<num;
	}
};
priority_queue<node>Q;
node r;
bool a[200002];
long long cnt[200002],b,c,i,n;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		r.id=i;
		scanf("%lld",&r.num);
		Q.push(r);
		scanf("%lld",&r.num);
		r.num+=1;
		Q.push(r);
	}
	b=Q.top().num;
	c=1;
	a[Q.top().id]=1;
	Q.pop();
	while(Q.size())
	{
		r=Q.top();
		Q.pop();
		cnt[c]+=r.num-b;
		b=r.num;
		c-=a[r.id]+a[r.id]-1;
		a[r.id]=a[r.id]^1;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld ",cnt[i]);
	}
}