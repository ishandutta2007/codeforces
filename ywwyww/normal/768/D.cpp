#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
double f[1010];
int ans[1010];
int main()
{
	int k,q;
	scanf("%d%d",&k,&q);
	memset(f,0,sizeof f);
	int d=1;
	f[0]=1;
	int i,j;
	for(i=1;d<=1000;i++)
	{
		for(j=k;j>=1;j--)
			f[j]=(f[j]*j+f[j-1]*(k-j+1))/k;
		while(d<=1000&&f[k]*2000>=(d-1e-7))
		{
			ans[d]=i;
			d++;
		}
		f[0]=0;
	}
	int x;
	for(i=1;i<=q;i++)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}