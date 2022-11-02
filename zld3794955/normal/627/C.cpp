#include<bits/stdc++.h>
using namespace std;
const int M=200200;
struct station
{
	int x,p;
}a[M]={};
struct print_cmp
{
	bool operator()(const station &s1,const station &s2)
	{
		return s1.p<s2.p || (s1.p==s2.p && s1.x<s2.x);	
	}
};
bool cmp(const station &s1,const station &s2)
{
	return s1.x<s2.x;
}
int d,n,m;
void init()
{
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&a[i].x,&a[i].p);
	++m;
	a[m].x=0;
	a[m].p=0;
	++m;
	a[m].x=d;
	a[m].p=0;
	sort(a+1,a+m+1,cmp);
}
void work()
{
	set<station,print_cmp> s;
	long long ans=0;
	int now=0,p=1;
	while(now<d)
	{
		while(p<=m && a[p].x<=now)
			s.insert(a[p++]);
		if(s.empty())
		{
			puts("-1");
			return;
		}
		station c=*s.begin();
		int tmp=now;
		now=max(now,c.x+n);
		now=min(now,a[p].x);
		if(now==tmp)
			s.erase(c);
		else
			ans+=c.p*1ll*(now-tmp);
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	work();
	return 0;
}