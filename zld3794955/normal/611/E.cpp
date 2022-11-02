#include<bits/stdc++.h>
using namespace std;
const int N=200020;
int n,a,b,c;
multiset<int> s,s0;
void init()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	if(b<c) swap(b,c);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		s.insert(x);
	}
}
inline void clear_upto(int c)
{
	auto it=s.upper_bound(c);
	if(it!=s.begin())
		s.erase(--it);
}
void work()
{
	int ans=0,ans2=1<<30;
	for(auto it=s.rbegin();it!=s.rend();it=s.rbegin())
	{
		if(*it>a+b+c)
		{	puts("-1"); return; }
		else if(a+b<*it && *it<=a+b+c)
		{	++ans; s.erase(s.find(*it)); }
		else if(a+c<*it && *it<=a+b)
		{	++ans; s.erase(s.find(*it)); clear_upto(c); }
		else if(max(a,b+c)<*it && *it<=a+c)
		{	++ans; s.erase(s.find(*it)); clear_upto(b); }
		else break;
	}
	if(a<=b+c)
	{
		for(auto it=s.rbegin();it!=s.rend();it=s.rbegin())
			if(a<*it && *it<=b+c)
			{	++ans; s.erase(s.find(*it)); clear_upto(a); }
			else break;
		int t1=0,t2=0,t3=0,y1=0,y2=0,y3=0;
		for(auto p:s)
		{
			t1+=p<=c;
			t2+=(c<p && p<=b);
			t3+=(b<p && p<=a);
		}
		for(int l=0;l<=t1+t2+t3;++l)
		{
			y1=t1,y2=t2,y3=t3;
			int x=l+l,d=min(t3,x);
			t3-=d,x-=d;
			d=min(t2,x);
			t2-=d,x-=d;
			d=min(t1,x);
			t1-=d,x-=d;
			ans2=min(l+max(max(t3,(t2+t3+1)/2),(t1+t2+t3+2)/3),ans2);
			t1=y1,t2=y2,t3=y3;
		}
	}
	else
	{
		int t1=0,t2=0,t3=0,t4=0,y1=0,y2=0,y3=0,y4=0;
		for(auto p:s)
		{
			t1+=p<=c;
			t2+=(c<p && p<=b);
			t3+=(b<p && p<=b+c);
			t4+=(b+c<p && p<=a);
		}
		for(int l=0;l<=t1+t2+t3+t4;++l)
		{
			y1=t1,y2=t2,y3=t3,y4=t4;
			int x1=l,x2=l,d1=min(t4,x1),d2=min(t3,x2);
			t4-=d1,x1-=d1;
			d1=min(x1,t3); t3-=d1,x1-=d1;
			d1=min(x1,t2); t2-=d1,x1-=d1;
			d1=min(x1,t1); t1-=d1,x1-=d1;
			t3-=d2,x2-=d2;
			d2=min(x2,t2); t2-=d2,x2-=d2;
			d2=min(x2,t1); t1-=d2,x2-=d2;
			ans2=min(l+max(max(t3+t4,(t2+t3+t4+1)/2),(t1+t2+t3+t4+2)/3),ans2);
			t1=y1,t2=y2,t3=y3,t4=y4;
		}
	}
	cout<<ans+ans2<<endl;
}
int main()
{
	init();
	work();
	return 0;
}