#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

ll n,k,a,b;

ll dfs(ll u)
{
	if(u==1) return 0;
	if(u%k==0&&(u-u/k)*a>b) return b+dfs(u/k);
	if(u%k==0) return (u-1)*a;
	return u%k*a+dfs(u-u%k);
}

int main()
{
	cin>>n>>k>>a>>b;
	cout<<dfs(n);
}