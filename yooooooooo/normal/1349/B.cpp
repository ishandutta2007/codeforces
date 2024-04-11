#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,k,a[100005];
bool ok;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		ok=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==k)ok=true;
		}
		if(ok==false)
		{
			printf("no\n");
			continue;
		}
		if(n==1)goto tag;
		for(int i=1;i<n;i++)if(a[i]>=k&&a[i+1]>=k)goto tag;
		for(int i=1;i<n-1;i++)if(a[i]>=k&&a[i+2]>=k)goto tag;
		printf("no\n");
		continue;
		tag:printf("yes\n");
	}
}