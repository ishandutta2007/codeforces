#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	ll A=(ll) b*(ll) (b-1)/2;
	ll B=(ll) a+(((ll) a*(ll) (a+1)/2)%MOD)*(ll) b%MOD;
	A%=MOD;
	B%=MOD;
	printf("%I64d\n",A*B%MOD);
	return 0;
}