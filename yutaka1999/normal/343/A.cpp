#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	ll a,b;
	scanf("%I64d %I64d",&a,&b);
	ll ret=0;
	while(b>0)
	{
		ret+=a/b;
		a%=b;
		swap(a,b);
	}
	printf("%I64d\n",ret);
	return 0;
}