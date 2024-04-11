#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 1050
using namespace std;
typedef long long LL;

LL a,b,x,y;

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

int main()
{
//	freopen("c.in","r",stdin);
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);
	
	LL g=gcd(x,y);
	
	x/=g,y/=g;
	
	printf("%I64d\n",min(a/x,b/y));
	return 0;
}