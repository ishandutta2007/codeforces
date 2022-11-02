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
const int M=100010;
typedef set<pair<int,int> >seg;
typedef seg::iterator iter;
struct point
{
	int x,y;
}p[M]={};
bool cmpx(const point &p1,const point &p2)
{
	return p1.x<p2.x;
}
bool cmp(const point &p1,const point &p2)
{
	return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
}
int n,m;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	p[0].x=0;
}
void work()
{
	int l=1,ry=n+1;
	sort(p+1,p+m+1,cmp);
	seg s;
	for(l=1;l<=m && p[l].x==1;++l)
		ry=min(ry,p[l].y);
	if(ry>1)
		s.insert(make_pair(1,ry-1));
	/*
		for(iter it=s.begin();it!=s.end();++it)
			cout<<"["<<it->first<<","<<it->second<<"]"<<endl;
		cout<<"-----------------"<<endl;
	*/
	while(l<=m && !s.empty())
	{
		int r=upper_bound(p+1,p+m+1,p[l],cmpx)-p;
		if(p[l].x>p[l-1].x+1)
		{
			int ly=s.begin()->first;
			s.clear();
			for(int i=l;i<r;++i)
			{
				if(p[i].y>ly)
					s.insert(make_pair(ly,p[i].y-1));
				ly=p[i].y+1;
			}
			if(n>=ly)
				s.insert(make_pair(ly,n));
		}
		else
		{
			seg tmp;
			iter it=s.begin();
			int ly=it->first;
			for(int i=l;i<r && it!=s.end();++i)
			{
				if(p[i].y >= it->second)
				{
					if(ly<p[i].y)
						tmp.insert(make_pair(ly,p[i].y-1));
					++it;
				}
				else
				{
					if(ly<p[i].y)
						tmp.insert(make_pair(ly,p[i].y-1));
					
				}
				ly=max(it->first,p[i].y+1);
				if(ly>s.rbegin()->second)
					break;
			}
				//cout<<"ly="<<ly<<" l="<<s.rbegin()->second<<endl;
			if(ly <= s.rbegin()->second)
				tmp.insert(make_pair(ly,n));
			s=tmp;
		}
		/*
		cout<<"x="<<p[l].x<<endl;
		for(iter it=s.begin();it!=s.end();++it)
			cout<<"["<<it->first<<","<<it->second<<"]"<<endl;
		cout<<"-----------------"<<endl;
		*/
		l=r;
	}
	if(s.empty())
	{
		puts("-1");
		return;
	}
	/*
		for(iter it=s.begin();it!=s.end();++it)
			cout<<"["<<it->first<<","<<it->second<<"]"<<endl;
		cout<<"-----------------"<<endl;
	*/
	if(p[m].x==n && s.rbegin()->second!=n)
		puts("-1");
	else
		printf("%d\n",n+n-2);
}
void reverse()
{
	for(int i=1;i<=m;++i)
	{
		p[i].x=n+1-p[i].x;
		p[i].y=n+1-p[i].y;
	}
}
int main()
{	
	init();
	work();
	return 0;
}