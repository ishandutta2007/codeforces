#include<stdio.h>
#include<algorithm>
using namespace std;
inline bool cmp(int x,int y)
{
	return x>y;
}
int a[200005],b[200005],t[200005];
int i,j,k,l,s,m,n,x,y;
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		t[x]++;
		t[y+1]--;
	}
	for (i=1;i<=n;i++)
	b[i]=b[i-1]+t[i];
	sort(b+1,b+1+n,cmp);
	for (i=1;i<=n;i++)
	ans=ans+1ll*a[i]*b[i];
	printf("%I64d\n",ans);
}