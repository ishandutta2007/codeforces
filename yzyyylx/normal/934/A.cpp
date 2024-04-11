#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#define N 60
#define ll long long
#define db double
using namespace std;

ll n,m,n1[N],n2[N],ans;

inline ll M(ll a,ll b,ll c,ll d)
{
	return max(max(a,b),max(c,d));
}

int main()
{
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&n1[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&n2[i]);
	}
	sort(n1+1,n1+n+1);
	sort(n2+1,n2+m+1);
	cout<<min(M(n1[n-1]*n2[m],n1[n-1]*n2[1],n1[1]*n2[m],n1[1]*n2[1]),M(n1[n]*n2[m],n1[n]*n2[1],n1[2]*n2[m],n1[2]*n2[1]));
}