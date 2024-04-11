#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 
using namespace std;

ll n,m;

int main()
{
	ll i,j,p,q=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		printf("%lld ",(p+q)/m);
		q=(p+q)%m;
	}//
}