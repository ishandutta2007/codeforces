#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005
#define INF 1000000000000000000LL

using namespace std;
typedef long long int ll;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	ll s1=0,s2=0,s3=0,s4=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ll a;
			scanf("%I64d",&a);
			s1+=a;
			s2+=a*(ll) (4*i+2);
			s3+=a*(ll) (4*j+2);
			s4+=a*(ll) ((4*i+2)*(4*i+2)+(4*j+2)*(4*j+2));
		}
	}
	ll mn=INF;
	int x,y;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m+1;j++)
		{
			ll cost=s1*(ll) (i*i+j*j)*16LL-(ll) 8*i*s2-(ll) 8*j*s3+s4;
			if(cost<mn)
			{
				mn=cost;
				x=i-1,y=j-1;
			}
		}
	}
	printf("%I64d\n",mn);
	printf("%d %d\n",x,y);
	return 0;
}