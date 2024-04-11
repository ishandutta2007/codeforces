#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll m,n,k,s,s1,s2,u,v;

int main()
{
	ll i,j;
	cin>>m>>n>>k;
	if(m+n-2<k)
	{
		cout<<-1;
		return 0;
	}
	if(m+n-2==k)
	{
		cout<<1;
		return 0;
	}
	if(k<=m-1||k<=n-1)
	{
		s=(m*n)/(k+1);
		s1=s/m*m;
		s2=s/n*n;
		cout<<max(s1,s2);
		return 0;
	}
	else
	{
		if(m>n) swap(m,n);//m<n
		u=k-(n-1);
		cout<<m/(u+1);
	}
}