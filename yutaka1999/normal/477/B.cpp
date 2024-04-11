#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long int ll;

int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int mx=((n-1)*6+5)*k;
	printf("%d\n",mx);
	for(int i=0;i<n;i++)
	{
		int a=i*6+1;
		int b=i*6+2;
		int c=i*6+3;
		int d=i*6+5;
		printf("%d %d %d %d\n",a*k,b*k,c*k,d*k);
	}
	return 0;
}