#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>

using namespace std;
typedef long long int ll;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll l,r;
		scanf("%I64d %I64d",&l,&r);
		ll ret=0;
		for(int i=62;i>=0;i--)
		{
			bool L=l>>i&1;
			bool R=r>>i&1;
			if(L&&R)
			{
				ret|=1LL<<i;
				r-=1LL<<i;
				l-=1LL<<i;
			}
			else if(!L&&R)
			{
				ll M=(1LL<<i)-1;
				if(r==(M|(1LL<<i)))
				{
					ret|=r;
					break;
				}
				else
				{
					ret|=M;
					break;
				}
			}
		}
		printf("%I64d\n",ret);
	}
	return 0;
}