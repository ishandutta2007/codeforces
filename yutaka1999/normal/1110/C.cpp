#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a;
		scanf("%d",&a);
		int ret=0;
		for(int i=0;i<29;i++)
		{
			if(a>>i&1)
			{
				ret=(1<<(i+1))-1;
			}
		}
		if(ret!=a) printf("%d\n",ret);
		else
		{
			ret=1;
			for(int i=2;i*i<=a;i++)
			{
				if(a%i==0)
				{
					ret=a/i;
					break;
				}
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}