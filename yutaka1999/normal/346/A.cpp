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
	int n;
	scanf("%d",&n);
	int mx=0,now=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(now==0) now=a;
		else now=gcd(now,a);
		mx=max(mx,a);
	}
	if((mx/now-n)%2==0) puts("Bob");
	else puts("Alice");
	return 0;
}