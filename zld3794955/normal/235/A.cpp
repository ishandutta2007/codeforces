#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int V=100;
int n;
inline long long gcd(long long a,long long b)
{
	return b ? gcd(b,a%b) : a;
}
inline long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{	
	cin>>n;
	long long ans=0;
	for(int i=max(1,n-V);i<=n;++i)
		for(int j=max(1,n-V);j<=n;++j)
			for(int k=max(1,n-V);k<=n;++k)
				ans=max(ans,lcm(i,lcm(j,k)));
	cout<<ans<<endl;
	return 0;
}