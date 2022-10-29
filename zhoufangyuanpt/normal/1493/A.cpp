#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);
		printf("%d\n",k/2+(n-k));
		for(int i=(k+1)/2;i<k;i++)printf("%d ",i);
		for(int i=k+1;i<=n;i++)printf("%d ",i);
		if(k/2+n-k>0)printf("\n");
	}
	return 0;
}