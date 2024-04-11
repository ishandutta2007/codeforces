#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int main()
{
	int p,k;
	scanf("%d %d",&p,&k);
	if(k==0)
	{
		ll ret=1;
		for(int i=0;i<p-1;i++)
		{
			ret*=(ll) p;
			ret%=MOD;
		}
		printf("%I64d\n",ret);
	}
	else
	{
		ll now=1;
		int cnt=0;
		do
		{
			now*=(ll) k;
			now%=p;
			cnt++;
		}while(now!=1);
		ll ret=k==1?p:1;
		for(int i=0;i<(p-1)/cnt;i++)
		{
			ret*=(ll) p;
			ret%=MOD;
		}
		printf("%I64d\n",ret);
	}
	return 0;
}