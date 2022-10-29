#include<cstdio>
#include<cstring>
using namespace std;
int f[110000],a[110000];
inline int mymax(int x,int y){return x>y?x:y;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)f[i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=2;i*j<=n;j++)
			{
				if(a[i]<a[i*j])
				{
					f[i*j]=mymax(f[i*j],f[i]+1);
				}
			}
		}
		int ss=0;
		for(int i=1;i<=n;i++)if(ss<f[i])ss=f[i];
		printf("%d\n",ss);
	}
	return 0;
}