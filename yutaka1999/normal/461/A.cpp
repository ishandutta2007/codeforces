#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 300005

using namespace std;
typedef long long int ll;

int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			ret+=(ll) in[i]*(ll) (i+2);
		}
		else
		{
			ret+=(ll) in[i]*(ll) (i+1);
		}
	}
	printf("%I64d\n",ret);
	return 0;
}