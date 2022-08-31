#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 305

using namespace std;
typedef long long int ll;

int main()
{
	ll x1,y1;
	scanf("%I64d %I64d",&x1,&y1);
	ll x2,y2;
	scanf("%I64d %I64d",&x2,&y2);
	int n;
	scanf("%d",&n);
	int ret=0;
	for(int i=0;i<n;i++)
	{
		ll a,b,c;
		scanf("%I64d %I64d %I64d",&a,&b,&c);
		ll v1=a*x1+b*y1+c;
		ll v2=a*x2+b*y2+c;
		if(v1>0&&v2<0) ret++;
		else if(v1<0&&v2>0) ret++;
	}
	printf("%d\n",ret);
	return 0;
}