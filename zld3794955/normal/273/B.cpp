#include<bits/stdc++.h>
using namespace std;
const int N=100010;
pair<int,int> p[N+N];
int n,mod;
long long ans=1;
long long calc(int x,int d)
{
	//cout<<"x="<<x<<" d="<<d<<endl;
	long long s=1;
	for(int i=1;i<=x;++i)
	{
		int tmp=i;
		while(d && tmp%2==0)
			tmp/=2,--d;
		s=s*tmp%mod;
	}
	//cout<<"s="<<s<<endl;
	return s;
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].first);
		p[i].second=i;
	}
	for(int i=n+1;i<=n+n;++i)
	{
		scanf("%d",&p[i].first);
		p[i].second=i-n;
	}
	scanf("%d",&mod);
	sort(p+1,p+n+n+1);
	int last=1,t=0;
	for(int i=1;i<=n+n;++i)
	{
		if(p[i].first!=p[last].first)
		{
			ans=ans*calc(i-last,t)%mod;
			last=i,t=0;
		}
		else
			t+=p[i].second==p[i-1].second;
	}
	ans=ans*calc(n+n+1-last,t)%mod;
	cout<<ans<<endl;
	return 0;
}