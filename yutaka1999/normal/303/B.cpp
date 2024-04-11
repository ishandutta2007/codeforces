#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n,m,x,y,a,b;
	scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&a,&b);
	int g=gcd(a,b);
	a/=g;b/=g;
	int kx=min(n/a,m/b);
	a*=kx;b*=kx;
	int x1=max(0,x-(a+1)/2);
	int y1=max(0,y-(b+1)/2);
	x1=min(x1,n-a);
	y1=min(y1,m-b);
	printf("%d %d %d %d\n",x1,y1,x1+a,y1+b);
	return 0;
}