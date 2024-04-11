#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 22

using namespace std;
typedef long long int ll;

int main()
{
	int a,c;
	scanf("%d %d",&a,&c);
	ll ret=0,t=1;
	for(;a>0||c>0;a/=3,c/=3,t*=3)
	{
		int d=c%3-a%3;
		if(d<0) d+=3;
		ret+=t*d;
	}
	printf("%I64d\n",ret);
	return 0;
}