#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b)
{
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(b%a,a);
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
ll lcm(ll a,ll b,ll c)
{
	return lcm(lcm(a,b),c);
}
ll solve(ll n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	if(n%2==1) return (n-2)*(n-1)*n;
	ll ret=solve(n-1);
	ret=max(ret,lcm(n-2,n-1,n));
	ret=max(ret,lcm(n-3,n-1,n));
	ret=max(ret,lcm(n-3,n-2,n));
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%I64d\n",solve((ll) n));
	return 0;
}