#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int cnt[SIZE];
int num[SIZE];
int rt[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*2%MOD;
	for(int i=0;i<SIZE;i++) rt[i]--;
	int ret=rt[n];
	for(int i=0;i<=20;i++)
	{
		for(int j=SIZE-1;j>=0;j--)
		{
			if(!(j>>i&1)&&(j|1<<i)<SIZE)
			{
				cnt[j]+=cnt[j|1<<i];
			}
		}
	}
	num[0]=0;
	for(int i=1;i<SIZE;i++)
	{
		num[i]=num[i&(i-1)]+1;
		if(num[i]%2==0) ret+=rt[cnt[i]];
		else ret+=MOD-rt[cnt[i]];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}