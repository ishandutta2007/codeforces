#include<bits/stdc++.h>
#define ll long long
#define N 1000000
#define M 10000000
using namespace std;
struct Milk 
{ 
	ll time,num; 
}milk[N+5];
ll n,m,k,i,m1[M+5],ans[N+5],minn,x,p;
bool cmp(Milk x,Milk y)
{ 
	return x.time>y.time; 
}
int main()
{
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		m1[x]++;
	}
	for(i=0;i<=M;i++)
	{
		if(i)
			m1[i]+=m1[i-1];
		if(m1[i]>(i+1)*k&&i<=n)
		{
			printf("-1");
			return 0;
		}
	}
	for(i=0;i<=M;i++)
		m1[i]=(i+1)*k-m1[i];
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&milk[i].time);
		milk[i].num=i;
	}
	sort(milk+1,milk+m+1,cmp);
	minn=m1[milk[1].time];
	for(i=1;i<=m&&minn;i++)
		if(minn&&m1[milk[i].time])
		{
			ans[++p]=milk[i].num;
			minn=min(--minn,--m1[milk[i].time]);
		}
	sort(ans+1,ans+p+1);
	cout<<p<<endl;
	for(i=1;i<=p;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}