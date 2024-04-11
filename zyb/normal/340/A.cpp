#include<stdio.h>
using namespace std;
inline int gcd(int o,int p)
{
	if (o%p==0)
	return p;
	return gcd(p,o%p);
}
int main()
{
	int ans=0,x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	int xx=gcd(x,y);
	int yy=x*y/xx;
	ans=b/yy-(a-1)/yy;
	printf("%d\n",ans);
}