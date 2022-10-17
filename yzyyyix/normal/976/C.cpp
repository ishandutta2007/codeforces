#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 300100
using namespace std;

ll n,m,k,t,mx;
struct Num
{
	ll a,b,id;
	bool operator < (const Num &u) const
	{
		if(a!=u.a) return a<u.a;
		return b>u.b;
	}
}num[N];

int main()
{
	ll i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&num[i].a,&num[i].b);
		num[i].id=i;
	}
	sort(num+1,num+n+1);
	for(i=2;i<=n;i++)
	{
		if(num[i].b<=num[i-1].b)
		{
			cout<<num[i].id<<" "<<num[i-1].id;
			return 0;
		}
	}
	puts("-1 -1");
}