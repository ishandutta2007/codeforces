#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n,a[30005],b[30005];
ll sum[2];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		a[n+1]=0;
		for(int i=1;i<=n+1;i++)b[i]=a[i]-a[i-1];
		sum[0]=sum[1]=0;
		for(int i=2;i<=n;i++)
		{
			if(b[i]>0)sum[0]+=b[i];
			else sum[1]-=b[i];
		}
		
		if(b[1]>=sum[1]&&-b[n+1]>=sum[0])
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}