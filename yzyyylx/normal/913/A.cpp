#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

ll n,m,now=1,k=2;

int main()
{
	int i,j;
	cin>>n>>m;
	for(;n;)
	{
		if(n&1) now*=k;
		if(now>m||k>m)
		{
			cout<<m;
			return 0;
		}
		k*=k;
		n>>=1;
	}
	cout<<m%now;
}