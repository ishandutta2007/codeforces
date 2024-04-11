#include<cstdio>
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	printf("%d\n",(n-2)/k+(n-3)/k+2);
	for (int i=2;i<=n;i++)
		printf("%d %d\n",i-k<1?1:i-k,i);
}