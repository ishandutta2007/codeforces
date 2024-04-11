#include<stdio.h>
using namespace std;
int f[100005],i,j,k,l,m,n,a[100005],x,y;
int s[100005];
inline bool check(int l,int r)
{
	int ll=l,rr=r;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (s[mid]==s[rr])
		r=mid;
		else
		l=mid+1;
	}
	if (f[r]-f[ll]==r-ll)
	return true;
	else return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	if (a[i]>=a[i-1])
	f[i]=f[i-1]+1;
	else
	f[i]=f[i-1];
	for (i=1;i<=n;i++)
	if (a[i]>a[i-1])
	s[i]=s[i-1]+1;
	else
	s[i]=s[i-1];
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if (check(x,y))
		printf("Yes\n");
		else
		printf("No\n");
	}
}