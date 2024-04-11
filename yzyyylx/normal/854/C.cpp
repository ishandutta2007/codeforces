#include<bits/stdc++.h>
#define N 300000
#define M 10000000
#define ll long long
using namespace std;

priority_queue<ll> A;
ll t[N+5],q[N+5],n,k;

int main()
{
	ll i,b;
	ll ans=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>q[i];
		q[i]*=M;
		q[i]+=i;
	}
	for(i=1;i<=n+k;i++)
	{
		if(i<=n)
		{
			A.push(q[i]);
		}
		if(i>k)
		{
			b=A.top();
			t[b%M]=i;
			ans+=(i-b%M)*(b/M);
			A.pop();
		}
	}
	
	cout<<ans<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<t[i]<<" ";
	}
}