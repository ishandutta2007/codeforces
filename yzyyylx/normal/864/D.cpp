#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;

ll n,m,num[N],P[N],ans;
queue<int>wa,need;
bool Q[N];

int main()
{
	ll i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		P[num[i]]++;
	}
	
	for(i=1;i<=n;i++)
	{
		if(P[i]==0)
		{
			need.push(i);
			ans++;
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(P[num[i]]>=2||num[i]>n)
		{
			wa.push(i);
		}
	}
	/*
	while(need.empty()==false)
	{
		cout<<need.front();
		need.pop();
	}
	return 0;
	//*/
	/*
	while(wa.empty()==false)
	{
		cout<<wa.front();
		wa.pop();
	}
	return 0;
	//*/
	while(wa.empty()==false)
	{
		j=wa.front();
		k=num[j];
		wa.pop();
		if(k<need.front()&&Q[k]==false||need.empty()==true||P[k]==1)
		{
			Q[k]=true;
		}
		else
		{
			num[j]=need.front();
			need.pop();
			P[k]--;
		}
	}
	
	cout<<ans<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}	
	return 0;
}