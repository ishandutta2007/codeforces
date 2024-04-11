#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int grundy(int n,int k)
{
	if(k%2==1)
	{
		if(n==0) return 0;
		if(n==1) return 1;
		if(n==2) return 0;
		if(n==3) return 1;
		int cnt=0,N=n;
		while(N%2==0)
		{
			cnt++;
			N/=2;
		}
		if(N==1) return 2-(cnt%2);
		if(N==3) return 1+(cnt%2);
		if(cnt==0) return 0;
		return 2-(cnt%2);
	}
	else
	{
		if(n==0) return 0;
		if(n==1) return 1;
		if(n==2) return 2;
		return 1-(n%2);
	}
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int xr=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int g=grundy(a,k);
		xr^=g;
	}
	if(xr==0) puts("Nicky");
	else puts("Kevin");
	return 0;
}