#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1010
using namespace std;

ll n,m,k,t;

int main()
{
	ll i,j;
	cin>>n>>m>>k;
	if(k<n)
	{
		cout<<k+1<<" "<<1;
		return 0;
	}
	k-=n-1;
	t=n-(k-1)/(m-1);
	cout<<t<<" ";
	if(t%2) cout<<m-(k-1)%(m-1);
	else cout<<(k-1)%(m-1)+2;
}