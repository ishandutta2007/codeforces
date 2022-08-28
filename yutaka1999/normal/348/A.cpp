#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define INF 1000000000000000005

using namespace std;
typedef long long int ll;

int in[SIZE];
int n;

bool ok(ll k)
{
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		if(in[i]>k) return false;
		sum+=k-in[i];
		sum=min(sum,k);
	}
	return sum>=k;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	ll s=0,e=INF;
	while(e-s>1)
	{
		ll med=(s+e)/2;
		if(ok(med)) e=med;
		else s=med;
	}
	printf("%I64d\n",e);
	return 0;
}