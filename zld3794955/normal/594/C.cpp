#include<bits/stdc++.h>
using namespace std;
const int N=101000;
struct point
{
	int x,y;
}p[N]={};
struct cmpx
{
	bool operator()(const point &p1,const point &p2)
	{
		return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
	}
};
struct cmpy
{
	bool operator()(const point &p1,const point &p2)
	{
		return p1.y<p2.y || (p1.y==p2.y && p1.x<p2.x);
	}
};
int n,k;
long long ans=1ll<<61;
multiset<point,cmpx> s1;
multiset<point,cmpy> s2;
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x1,y1,x2,y2;i<=n;++i)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		p[i].x=x1+x2;
		p[i].y=y1+y2;
		s1.insert(p[i]),s2.insert(p[i]);
	}
}
void tryy(int t,int k)
{
	if(k==0)
	{
		int a=max(s1.rbegin()->x - s1.begin()->x,1);
		int b=max(s2.rbegin()->y - s2.begin()->y,1);
		ans=min(ans,((a+1)/2) *1ll *((b+1)/2));
		return;
	}
	point tmp={0,0};
	if(t==1)
	{
		tmp=*s1.begin();
		s1.erase(s1.find(tmp));
		s2.erase(s2.find(tmp));
	}
	if(t==2)
	{
		tmp=*s1.rbegin();
		s1.erase(s1.find(tmp));
		s2.erase(s2.find(tmp));
	}
	if(t==3)
	{
		tmp=*s2.begin();
		s1.erase(s1.find(tmp));
		s2.erase(s2.find(tmp));
	}
	if(t==4)
	{
		tmp=*s2.rbegin();
		s1.erase(s1.find(tmp));
		s2.erase(s2.find(tmp));
	}
	for(int d=t;d<=4;++d)
		tryy(d,k-1);
	s1.insert(tmp);
	s2.insert(tmp);
}
void work()
{
	for(int i=1;i<=4;++i)
		tryy(i,k);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}