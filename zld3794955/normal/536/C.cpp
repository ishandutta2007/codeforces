#include<bits/stdc++.h>
using namespace std;
const int N=200020;
struct point
{
	int x,y;
}a[N]={},p[N]={},s[N]={};
bool can[N]={};
int n,ans[N]={},top=0,m=0;
bool can_del(const point &a,const point &b,const point &c)
{
	return (long long)(c.x*b.y)*((a.x-b.x)*(a.y-c.y))<(long long)(b.x*c.y)*((a.x-c.x)*(a.y-b.y));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	copy(a+1,a+n+1,p+1);
	sort(p+1,p+n+1,[](const point &p1,const point &p2)
					{return p1.x>p2.x || (p1.x==p2.x && p1.y>p2.y);});
	for(int i=1;i<=n;++i)
		if(p[i].y>p[i-1].y)
			p[++m]=p[i];
	for(int i=1;i<=m;++i)
	{
		while(top>=2 && can_del(s[top-1],s[top],p[i]))
			--top;
		s[++top]=p[i];
	}
	set<pair<int,int> > win;
	win.insert({s[1].x,s[1].y});
	for(int i=2; i<=top && s[i].y>s[i-1].y; ++i)
		win.insert({s[i].x,s[i].y});
	for(int i=1;i<=n;++i)
		if(win.count({a[i].x,a[i].y}))
			printf("%d ",i);
	puts("");
	return 0;
}