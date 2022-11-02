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
const int N=101000,Bit=18;
set<int>s[Bit];
int n,m;
long long ans=0;
inline long long C2(long long n) { return n*(n+1)/2; }
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		for(int b=0;b<Bit;++b)
			if(!(x&(1<<b)))
				s[b].insert(i);
	}
	for(int b=0;b<Bit;++b)
		s[b].insert(0),s[b].insert(n+1);
	for(int b=0;b<Bit;++b)
	{
		set<int>::iterator it=s[b].begin();
		int last=*(it++);
		for(;it!=s[b].end();last=*(it++))
			ans+=(1ll<<b)*C2(*it-last-1);
	}
}
void work()
{
	int p,v;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&p,&v);
		for(int b=0;b<Bit;++b)
		{
			if(v&(1<<b))
			{
				set<int>::iterator it=s[b].find(p);
				if(it!=s[b].end())
				{
					set<int>::iterator prev=it; --prev;
					set<int>::iterator next=it; ++next;
					ans-=(1ll<<b)*C2(*it-*prev-1);
					ans-=(1ll<<b)*C2(*next-*it-1);
					ans+=(1ll<<b)*C2(*next-*prev-1);
					s[b].erase(it);
				}
			}
			else
			{
				set<int>::iterator it=s[b].find(p);
				if(it==s[b].end())
				{
					it=s[b].insert(p).first;
					set<int>::iterator prev=it; --prev;
					set<int>::iterator next=it; ++next;
					ans+=(1ll<<b)*C2(*it-*prev-1);
					ans+=(1ll<<b)*C2(*next-*it-1);
					ans-=(1ll<<b)*C2(*next-*prev-1);
				}
			}
		}
		printf("%I64d\n",ans);
	}
}
int main()
{	
	init();
	work();
	return 0;
}