#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 205000
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[maxn]={-(1<<30)};

int neg,zero,pos;

int pn=0,pz=-1;

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout); 
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if (a[i]<0)
		{
			++neg;
			if (a[pn]<a[i])
				pn=i;
		}
		if (a[i]==0)
		{
			++zero;
			if (~pz)
				printf("1 %d %d\n",pz,i);
			pz=i;
		}
		if (a[i]>0)	++pos;
	}
	
	if (neg&1)
	{
		if (~pz)
			printf("1 %d %d\n",pz,pn);
		if (zero+1!=n)
			printf("2 %d\n",pn);
	} else
	{
		pn=-1;
		if (zero&&zero!=n)
			printf("2 %d\n",pz);
	}
	
	int k=-1;
	for (int i=1;i<=n;++i)
	{
		if (!a[i]||i==pn)	continue;
		if (~k)
			printf("1 %d %d\n",k,i);
		k=i;
	}
	return 0;
}