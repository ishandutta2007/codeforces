#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	ll num=0;
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		num+=r-l+1;
	}
	if(num%k==0) printf("%d\n",0);
	else printf("%I64d\n",(num/k+1)*k-num);
	return 0;
}