#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;

ll A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		sum+=A[i];
	}
	ll ret=sum;
	for(int i=n-1;i>1;i--)
	{
		sum-=A[i];
		ll dp=sum-ret;
		ret=max(ret,dp);
	}
	printf("%lld\n",ret);
	return 0;
}