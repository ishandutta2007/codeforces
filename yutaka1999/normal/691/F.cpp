#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 3000005

using namespace std;
typedef long long int ll;

ll ans[SIZE];
ll cnt[SIZE];

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
	for(int i=1;i<SIZE;i++)
	{
		for(int j=1;i*j<SIZE;j++)
		{
			if(i!=j) ans[i*j]+=cnt[i]*cnt[j];
			else ans[i*i]+=cnt[i]*(cnt[i]-1);
		}
	}
	for(int i=1;i<SIZE;i++) ans[i]+=ans[i-1];
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int p;
		scanf("%d",&p);
		printf("%lld\n",(ll) n*(ll) (n-1)-ans[p-1]);
	}
	return 0;
}