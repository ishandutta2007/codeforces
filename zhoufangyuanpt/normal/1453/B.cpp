#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[210000];
inline int mymin(int x,int y){return x<y?x:y;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		long long ss=0,s=0;
		for(int i=1;i<n;i++)
		{
			int aa=a[i]-a[i+1];
			ss=ss+abs(aa);
		}
		if(n>1&&s<abs(a[1]-a[2]))s=abs(a[1]-a[2]);
		if(n>1&&s<abs(a[n-1]-a[n]))s=abs(a[n-1]-a[n]);
		for(int i=2;i<n;i++)
		{
			if(a[i]<a[i-1]&&a[i]<a[i+1]||a[i]>a[i-1]&&a[i]>a[i+1])
			{
		int aa=mymin(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
					if(s<aa*2ll)s=aa*2ll;
			}
		}
		printf("%lld\n",ss-s);
	}
	return 0;
}