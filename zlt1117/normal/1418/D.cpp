#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define iter multiset<int>::iterator 
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
multiset<int>s;
multiset<int>ans;
int n,m,a[maxn];
inline void output()
{
	if(s.size()<=2)
	{
		printf("0\n");
		return ;
	}
	iter it=s.end();
	--it;
	int dist=(*it)-(*s.begin());
	it=ans.end();
	--it;
	printf("%d\n",dist-(*it));
}
int main()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi();
	sort(a+1,a+n+1);
	FOR(i,1,n)s.insert(a[i]);
	FOR(i,2,n)ans.insert(a[i]-a[i-1]);
	output();
	FOR(i,1,m)
	{
		int t=gi(),x=gi();
		if(t==0)
		{  
			iter it1=s.upper_bound(x);
			if(it1!=s.end())ans.erase(ans.find((*it1)-x));
			iter it2=s.lower_bound(x);
			if(it2!=s.begin())
			{
				--it2;
				int val=x-(*it2);
				ans.erase(ans.find(val));
			}
			//it1=s.upper_bound(x);
			it2=s.lower_bound(x);
			if(it1!=s.end()&&it2!=s.begin())
			{
				--it2;
				ans.insert((*it1)-(*it2));
			}
			s.erase(s.find(x));
		}
		else
		{
			iter it1=s.upper_bound(x);
			if(it1!=s.end())ans.insert((*it1)-x);
			iter it2=s.lower_bound(x);
			if(it2!=s.begin())
			{
				--it2;
				ans.insert(x-(*it2));
			}
			//it1=s.upper_bound(x);
			it2=s.lower_bound(x);
			if(it1!=s.end()&&it2!=s.begin())
			{
				--it2;
				ans.erase(ans.find((*it1)-(*it2)));
			}
			s.insert(x);
		}
		output();
	}
	return 0;
}