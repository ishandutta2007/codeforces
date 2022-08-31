#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	scanf("%I64d",&n);
	ll t=1;
	while(1)
	{
		if(n%t!=0)
		{
			printf("%I64d\n",(n/t)+1);
			return 0;
		}
		t*=3;
	}
	return 0;
}