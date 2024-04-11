#include<cstdio>

using namespace std;

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);n--;
		if(n%2==1){printf("%d %d %d\n",n/2,(n+1)/2,1);}
		else{if(n%4==0)printf("%d %d %d\n",n/2+1,n/2-1,1);else printf("%d %d %d\n",n/2+2,n/2-2,1);}
	}
}