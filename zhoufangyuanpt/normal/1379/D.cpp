#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int x,p;
}a[210000];
inline bool cmp(node x,node y){return x.x<y.x;}
int main()
{
	int n,m,k;scanf("%d%*d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%*d%d",&a[i].x);
		if(a[i].x>m/2)a[i].x-=m/2;
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)a[i+n].x=a[i].x+m/2,a[i+n].p=a[i].p;
	int j=1,s=n,pp=0,b=0;
	for(int i=1;i<=n;i++)
	{
		while(a[j].x-a[i].x<k)j++;
		if(j-i-1<s)s=j-i-1,pp=i;
	}
	printf("%d %d\n",s,(a[pp].x+k)%(m/2));
	for(int i=pp+1;i<=2*n;i++)
	{
		if(a[i].x-a[pp].x>=k)break;
		printf("%d ",a[i].p);
	}
	printf("\n");
	return 0;
}