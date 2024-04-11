#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int a[100010];
int b[100010];
int c[100010];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=c[i]=a[i];
	}
	for(i=2;i<=n;i++)
		b[i]=min(b[i],b[i-1]);
	for(i=n-1;i>=1;i--)
		c[i]=min(c[i],c[i+1]);
	if(k==1)
		printf("%d\n",b[n]);
	else if(k==2)
	{
		int ans=0x80000000;
		for(i=1;i<=n-1;i++)
			ans=max(ans,max(b[i],c[i+1]));
		printf("%d\n",ans);
	}
	else
	{
		int ans=0x80000000;
		for(i=1;i<=n;i++)
			ans=max(ans,a[i]);
		printf("%d\n",ans);
	}
	return 0;
}