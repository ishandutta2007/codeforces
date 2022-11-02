#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<fstream>
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
#include<stdexcept>
#include<iomanip>
#include<functional>
using namespace std;
int n,m,a[5050]={},b[5050]={},g[5050]={},ans=0;
int prime[20100]={},p=0;
set<int>s;
int get_score(int x)
{
	int score=0;
	for(int j=1;j<=p && prime[j]*prime[j]<=x;++j)
	{	
		int d=(s.find(prime[j])==s.end()) ? 1 : -1;
		while(x%prime[j]==0)
			score+=d,x/=prime[j];
	}
	if(x==1)
		return score;
	if(s.find(x)==s.end())
		return score+1;
	else
		return score-1;
}
int gcd(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
void init()
{
	bool c[50500]={};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
	{	
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	for(int i=2;i<=50000;++i)
	{
		if(!c[i])
			prime[++p]=i;
		for(int j=1;j<=p && i*prime[j]<=50000;++j)
		{
			c[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
void work()
{
	g[1]=a[1];
	for(int i=2;i<=n;++i)
		g[i]=gcd(g[i-1],a[i]);
	for(int i=n;i>=1;--i)
	{
		int s=get_score(g[i]);
		if(s<0)
		{
			for(int j=1;j<=i;++j)
				a[j]/=g[i],g[j]/=g[i];
		}
	}
	for(int i=1;i<=n;++i)
		ans+=get_score(a[i]);
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}