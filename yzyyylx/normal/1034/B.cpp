#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 
#define M 
using namespace std;

ll n,m;

inline ll ca1(ll u){return u/6*6+max(0ll,n%6-3)*2;}

int main()
{
	ll i,j;
	cin>>m>>n;
	if(n<m) swap(n,m);
	if(n%6==0||m%6==0)
	{
		cout<<n*m;
		return 0;
	}
	if(n==2&&m==2)
	{
		puts("0");
		return 0;
	}
	if(n%2==0&&m%2==0)
	{
		cout<<m*n;
		return 0;
	}
	if(m==1)
	{
		cout<<ca1(n);
		return 0;
	}
	if(m==2)
	{
		if(n==3||n==7) cout<<m*n-2;
		else cout<<m*n;
		return 0;
	}
	if(m==3)
	{
		cout<<m*n-n%2;
		return 0;
	}
	if(m==4)
	{
		cout<<m*n;
		return 0;
	}
	if(m==5)
	{
		cout<<m*n-n%2;
		return 0;
	}
	cout<<m*n/2*2;
}