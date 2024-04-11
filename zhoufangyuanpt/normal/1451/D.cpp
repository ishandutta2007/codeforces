#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);
		long long j=0;
		while(2*(j+k)*(j+k)<=1ll*n*n)j+=k;
		if((j+k)*(j+k)+j*j<=1ll*n*n)puts("Ashish");
		else puts("Utkarsh");
	}
	return 0;
}