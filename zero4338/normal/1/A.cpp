#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a,n,m;
long long ans=1;
int main()
{
	cin>>n>>m>>a;
	if(n%a==0)ans*=n/a;
    else ans*=(n/a)+1;
	if(m%a==0)ans*=m/a;
    else ans*=(m/a)+1;
    cout<<ans;
	return 0;
}