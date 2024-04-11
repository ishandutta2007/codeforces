#include<cstdio>
#include<cstring>
using namespace std;
int a[410000];
inline int mymax(int x,int y){return x>y?x:y;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		a[0]=a[n+1]=0;
		long long ss=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1])ss+=a[i]-a[i-1];
			if(a[i]>a[i+1])ss+=a[i]-a[i+1];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])
			{
				ss-=a[i]-mymax(a[i-1],a[i+1]);
			}
		}
		printf("%lld\n",ss);
	}
	return 0;
}