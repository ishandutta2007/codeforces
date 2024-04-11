#include<stdio.h>
#include<algorithm>
#define lowbit(o) (o&(-o))
using namespace std;
struct node
{
	int x,y,z;
}a[500005];
int f[500005];
int i,j,k,l,s,m,n,may,ans;
inline bool cmp1(node x,node y)
{
	return x.x<y.x;
}
inline bool cmp2(node x,node y)
{
	return x.y<y.y;
}
inline bool cmp3(node x,node y)
{
	return x.z<y.z;
}
inline bool cmp4(node x,node y)
{
	if (x.x>y.x)
	return true;
	if (x.x==y.x&&x.z<y.z)
	return true;
	return false;
}
inline void insert(int o,int p)
{
	for (;o;o-=lowbit(o))
	f[o]=max(f[o],p);
}
inline int ask(int o)
{
	int gtw=0;
	for (;o<=may;o+=lowbit(o))
	gtw=max(gtw,f[o]);
	return gtw;
}
inline void ls()
{
	sort(a+1,a+1+n,cmp1);
	int tot=0;
	int last=-1;
	for (i=1;i<=n;i++)
	{
		if (a[i].x!=last)
		tot++;
		last=a[i].x;
		a[i].x=tot;
	}
	sort(a+1,a+1+n,cmp2);
	tot=0;
	last=-1;
	for (i=1;i<=n;i++)
	{
		if (a[i].y!=last)
		tot++;
		last=a[i].y;
		a[i].y=tot;
	}
	may=tot;
	sort(a+1,a+1+n,cmp3);
	tot=0;
	last=-1;
	for (i=1;i<=n;i++)
	{
		if (a[i].z!=last)
		tot++;
		last=a[i].z;
		a[i].z=tot;
	}
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i].x);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i].y);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i].z);
	ls();
	sort(a+1,a+1+n,cmp4);
	for (i=1;i<=n;i++)
	{
		int gt=ask(a[i].y+1);
		if (gt>a[i].z)
		ans++;
		insert(a[i].y,a[i].z);
	}
	printf("%d\n",ans);
}