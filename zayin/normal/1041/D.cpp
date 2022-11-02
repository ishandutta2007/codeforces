#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 205000
using namespace std;

int n,h;
int L[maxn],R[maxn];

int pos[maxn];

bool cmp(int i,int j)
{
	return L[i]<L[j];
}

void init()
{
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&L[i],&R[i]);
		pos[i]=i;
	}
	sort(pos+1,pos+n+1,cmp);
}

void solve()
{
	R[0]=L[1];
	
	int ans=0,sum=R[1]-L[1],d=0;
	for (int i=1,j=1;i<=n;++i)
	{
		while (j<n&&L[j+1]-R[j]+d<=h)	++j,d+=L[j]-R[j-1],sum+=R[j]-L[j];
		
		if (d==h)
			ans=max(ans,sum-(R[j]-L[j]));
		else
			ans=max(ans,sum);
		
			
//		printf("%d %d %d %d\n",i,sum,d,j);
		
		sum-=R[i]-L[i];
		
		if (j>i)
			d-=L[i+1]-R[i];
		else
		if (i==j)
			d=0,++j,sum=R[j]-L[j];
		
	}
	printf("%d\n",ans+h);
}

int main()
{
//	freopen("c.in","r",stdin);
	init();
	solve(); 
	return 0;
}