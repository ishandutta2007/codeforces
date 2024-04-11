#include<cstdio>
#include<cstring>
using namespace std;
char a[110000];
int f[210000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,p,k;scanf("%d%d%d",&n,&p,&k);
		scanf("%s",a+1);
		long long x,y;scanf("%lld%lld",&x,&y);
		long long ss=0x3f3f3f3f3f3f3f3fll;
		for(int i=n+1;i<=n+k;i++)f[i]=0;
		for(int i=n;i>=p;i--)
		{
			f[i]=f[i+k]+(a[i]=='0');
			if(f[i]*x+(i-p)*y<ss)ss=f[i]*x+(i-p)*y;
		}
		printf("%lld\n",ss);
	}
	return 0;
}