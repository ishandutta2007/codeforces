#include<stdio.h>
int n,m,h;
int a[102],b[102],c;
inline int Min(int a,int b){return a<b?a:b;}
main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&c);
			printf("%d ",c*Min(a[j],b[i]));
		}putchar('\n');
	}
}