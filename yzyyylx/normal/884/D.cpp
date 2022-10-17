#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue<ll,vector<ll>,greater<ll> >pq;
ll n,ans,tmp;

int main()
{
	ll i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		pq.push(p);
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n%2==0) pq.push(0);
	while(pq.size()>3)
	{
		tmp=pq.top();
		pq.pop();
		tmp+=pq.top();
		pq.pop();
		tmp+=pq.top();
		pq.pop();
		ans+=tmp;
		pq.push(tmp);
	}
//	cout<<pq.empty();
	while(!pq.empty())
	{
		ans+=pq.top();
		pq.pop();
	}
	printf("%lld",ans);
}