#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k,i;scanf("%d%d",&n,&k);k--;
		for(i=2;i<=n;i++)if(n%i==0)break;
		n=n+i;printf("%d\n",n+2*k);
	}
	return 0;
}