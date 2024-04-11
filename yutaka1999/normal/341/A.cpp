#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int in[SIZE];

ll gcd(ll x,ll y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	ll ret=0;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		ret+=(ll) in[i]*i-sum;
		sum+=in[i];
	}
	ret*=2;
	ret+=sum;
	ll g=gcd(ret,n);
	printf("%I64d %d\n",ret/g,n/g);
	return 0;
}