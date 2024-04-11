#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 755

using namespace std;
typedef long long int ll;

int A[SIZE];
ll mn[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
	{
		ll sum=0;
		mn[i]=0;
		for(int j=i;j<n;j++)
		{
			if(A[j]>=A[i])
			{
				sum+=A[j];
				mn[i]=min(mn[i],sum);
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		ll B;
		scanf("%lld",&B);
		int ret=0;
		for(int j=0;j<n;j++)
		{
			if(B+mn[j]<0) ret++;
			else B+=A[j];
		}
		printf("%d\n",ret);
	}
	return 0;
}