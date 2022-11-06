#include<stdio.h>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
int a[1002][1002],b[1002][1002],c[1002],d[1002],n,m,i,j,l,cnt;
struct node
{
	int id,h;
	bool operator<(const node &u)const{return h<u.h;}
}e[1002];
main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&a[i][j]),b[i][j]=a[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)e[j].h=a[i][j],e[j].id=j;l=0;cnt=0;
		std::sort(e+1,e+m+1);
		for(j=1;j<=m;j++)a[i][e[j].id]=(cnt+=(l!=e[j].h)),l=e[j].h;c[i]=cnt;
	}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)e[i].h=b[i][j],e[i].id=i;l=0;cnt=0;
		std::sort(e+1,e+n+1);
		for(i=1;i<=n;i++)b[e[i].id][j]=(cnt+=(l!=e[i].h)),l=e[i].h;d[j]=cnt;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)printf("%d ",Max(a[i][j],b[i][j])+Max(c[i]-a[i][j],d[j]-b[i][j]));
		putchar('\n');
	}
}