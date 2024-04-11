#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	ll ret=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i*i+j*j)%m==0)
			{
				if(i<=n&&j<=n)
				{
					int a=(n-i+m)/m;
					int b=(n-j+m)/m;
					ret+=(ll) a*(ll) b;
				}
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}