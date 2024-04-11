#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,p,q;
		scanf("%d %d %d %d",&x,&y,&p,&q);
		if(p==q)//==1
		{
			if(x==y) puts("0");
			else puts("-1");
		}
		else if(p==0)
		{
			if(x==0) puts("0");
			else puts("-1");
		}
		else
		{
			int s=(x+p-1)/p,t=((y-x)+(q-p)-1)/(q-p);
			printf("%lld\n",(ll) max(s,t)*(ll) q-(ll) y);
		}
	}
	return 0;
}