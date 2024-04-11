#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	scanf("%lld",&n);
	if(n==1)
	{
		puts("1");
		return 0;
	}
	ll all=n;
	vector <ll> pr;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			pr.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n!=1) pr.push_back(n);
	if(pr.size()>=2)
	{
		puts("1");
		return 0;
	}
	printf("%lld\n",pr[0]);
	return 0;
}