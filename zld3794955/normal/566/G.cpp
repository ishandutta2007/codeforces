#include<bits/stdc++.h>
using namespace std;
const int N=100100,M=100100;
struct point
{
	int x,y;
}p[N]={},q[M]={},s[M]={};
bool point_cmp(const point &p1,const point &p2)
{
	return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
}
int n,m,a,b,dx[M]={},maxy[M]={};
void init()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&q[i].x,&q[i].y);
	sort(q+1,q+m+1,point_cmp);
}
bool can_del(const point &a,const point &b,const point &c)
{
	return (long long)(b.x-a.x)*(c.y-a.y)-(long long)(c.x-a.x)*(b.y-a.y)>=0;
}
void work()
{
	int top=0;
	for(int i=1;i<=m;++i)
	{
		while(top>=2 && can_del(s[top-1],s[top],q[i]))
			--top;
		s[++top]=q[i];
	}
	for(int i=1;i<=top;++i)
		dx[i]=s[i].x;
	for(int i=top;i>=0;--i)
		maxy[i]=max(maxy[i+1],s[i].y);
	for(int i=1;i<=n;++i)
	{
		int pos=upper_bound(dx+1,dx+top+1,p[i].x)-dx;
		if(pos<=top)
		{
			long long d1=(long long)(dx[pos]-dx[pos-1])*(p[i].y-maxy[pos-1]);
			long long d2=(long long)(p[i].x-dx[pos-1])*(maxy[pos]-maxy[pos-1]);
			if(d1-d2<0)
				continue;
		}
		puts("Max");
		return;
	}
	puts("Min");
}
int main()
{
	init();
	work();
	return 0;
}