#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 1050
using namespace std;

int n,m,a[maxn];

int main()
{
//	freopen("c.in","r",stdin):
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n);
	
	int ans1,ans2=a[n-1]+m;
	for (int i=0;i<n;++i)
		m-=min(a[n-1]-a[i],m);
	if (m)
		ans1=a[n-1]+(m+n-1)/n;
	else
		ans1=a[n-1];
	printf("%d %d\n",ans1,ans2);
	return 0;
}