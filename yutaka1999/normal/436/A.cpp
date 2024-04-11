#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 2005

using namespace std;

struct P
{
	int t,h,x;
	P(int t=0,int h=0,int x=0):t(t),h(h),x(x){}
	bool operator<(const P&l) const
	{
		return h<l.h;
	}
};
P pos[SIZE];
priority_queue <int> one,two;

int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=0;i<n;i++)
	{
		int t,h,x;
		scanf("%d %d %d",&t,&h,&x);
		pos[i]=P(t,h,x);
	}
	sort(pos,pos+n);
	int ret=0,cnt;
	int e,now,bt;
	//first, one
	e=0;now=x;
	while(e<n&&pos[e].h<=now)
	{
		if(pos[e].t==0) one.push(pos[e].x);
		else two.push(pos[e].x);
		e++;
	}
	cnt=0;
	bt=0;
	while(1)
	{
		if(bt==0)
		{
			if(one.empty()) break;
			now+=one.top();one.pop();
		}
		else
		{
			if(two.empty()) break;
			now+=two.top();two.pop();
		}
		cnt++;
		bt^=1;
		while(e<n&&pos[e].h<=now)
		{
			if(pos[e].t==0) one.push(pos[e].x);
			else two.push(pos[e].x);
			e++;
		}
	}
	ret=max(ret,cnt);
	while(!one.empty()) one.pop();
	while(!two.empty()) two.pop();
	//first, two
	e=0;now=x;
	while(e<n&&pos[e].h<=now)
	{
		if(pos[e].t==0) one.push(pos[e].x);
		else two.push(pos[e].x);
		e++;
	}
	cnt=0;
	bt=1;
	while(1)
	{
		if(bt==0)
		{
			if(one.empty()) break;
			now+=one.top();one.pop();
		}
		else
		{
			if(two.empty()) break;
			now+=two.top();two.pop();
		}
		cnt++;
		bt^=1;
		while(e<n&&pos[e].h<=now)
		{
			if(pos[e].t==0) one.push(pos[e].x);
			else two.push(pos[e].x);
			e++;
		}
	}
	ret=max(ret,cnt);
	printf("%d\n",ret);
	return 0;
}