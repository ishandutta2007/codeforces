#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll L[SIZE];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&L[i]);
	scanf("%s",&str);
	ll ret=0;
	ll walk=0,swim=0;
	ll mn=5;
	for(int i=0;i<n;i++)
	{
		char c=str[i];
		if(i==0)
		{
			if(c=='G')
			{
				ret=L[i]*3LL;
				walk=L[i];
			}
			else
			{
				ret=L[i]*2LL;
				swim=L[i];
				mn=3;
			}
		}
		else
		{
			if(c=='W')
			{
				swim+=L[i];
				ret+=L[i]*2LL;
				mn=3;
			}
			else
			{
				ll u=min(swim,L[i]);
				swim-=u,L[i]-=u;
				ret+=u*2LL;
				if(c=='G') walk+=u*2LL;
				if(L[i]>0)
				{
					if(c=='G')
					{
						walk+=L[i];
						ret+=L[i]*3LL;
					}
					else
					{
						u=min(walk,L[i]);
						walk-=u,L[i]-=u;
						ret+=u*3LL;
						ret+=L[i]*(mn+1LL);
					}
				}
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}