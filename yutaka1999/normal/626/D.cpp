#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 2005
#define MX 5005

using namespace std;
typedef long long int ll;

int A[SIZE];
int cnt[MX];
int rt[MX];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cnt[abs(A[i]-A[j])]++;
		}
	}
	for(int i=MX-1;i>=0;i--)
	{
		rt[i]=cnt[i];
		if(i+1<MX) rt[i]+=rt[i+1];
	}
	ll ret=0,all=n*(n-1)/2;
	all=all*all*all;
	for(int i=0;i<MX;i++)
	{
		for(int j=0;i+j+1<MX;j++)
		{
			ret+=(ll) cnt[i]*(ll) cnt[j]*(ll) rt[i+j+1];
		}
	}
	printf("%.10f\n",(double) ret/(double) all);
	return 0;
}