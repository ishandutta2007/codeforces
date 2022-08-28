#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define SQR 450

using namespace std;

int A[SIZE],ans[SIZE];
int imos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=1;i<n;i++)
	{
		int cnt=0,lim=-1;
		for(int j=1;;j++)
		{
			int par=(i-1)/j;
			if(par<=j)
			{
				lim=par;
				break;
			}
			ans[j]+=A[par]>A[i];
		}
		while(lim>=0)
		{
			//[(i-1)/t]==par
			//par<=(i-1)/t<par+1
			//par/(i-1)<=1/t<(par+1)/(i-1)
			//(i-1)/(par+1)<t<=(i-1)/par
			int s=(i-1)/(lim+1);
			int t=lim==0?n-1:(i-1)/(lim);
			if(A[lim]>A[i])
			{
				imos[s+1]++;
				imos[t+1]--;
			}
			lim--;
		}
	}
	for(int i=0;i<n;i++) imos[i+1]+=imos[i];
	for(int i=1;i<=n-1;i++)
	{
		if(i!=1) printf(" ");
		printf("%d",ans[i]+imos[i]);
	}
	puts("");
	return 0;
}