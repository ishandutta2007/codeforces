#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int a[20];
int b[20];
ll n;
int m;
ll f[1<<18][100];
int main()
{
//	freopen("cf401d.in","r",stdin);
//	freopen("cf401d.out","w",stdout);
	scanf("%I64d%d",&n,&m);
	int i,j,k;
	int len=0;
	while(n)
	{
		len++;
		a[len]=n%10;
		n/=10;
	}
	f[(1<<len)-1][0]=1;
	for(i=(1<<len)-1;i;i--)
	{
		memset(b,0,sizeof b);
		for(j=1;j<=len;j++)
			if(i&(1<<(j-1))&&!b[a[j]]&&(i!=(1<<len)-1||a[j]))
			{
				for(k=0;k<=m-1;k++)
					f[i^(1<<(j-1))][(k*10+a[j])%m]+=f[i][k];
				b[a[j]]=1;
			}
	}
	printf("%I64d\n",f[0][0]);
	return 0;
}