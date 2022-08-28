#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 10000007

using namespace std;
typedef long long int ll;

ll cnt[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	ll sum=0;
	for(int i=SIZE-1;i>=1;i--)
	{
		sum+=cnt[i];
		if(i*2+1<SIZE)
		{
			sum+=cnt[i*2+1];
			cnt[i]+=cnt[i*2+1];
			cnt[i+1]+=cnt[i*2+1];
		}
		if(i*2<SIZE)
		{
			sum+=cnt[i*2];
			cnt[i]+=cnt[i*2]*2LL;
		}
		if(sum>=k)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}