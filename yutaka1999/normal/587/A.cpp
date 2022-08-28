#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 2000005

using namespace std;

int cnt[SIZE];

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
	for(int i=0;i+1<SIZE;i++)
	{
		cnt[i+1]+=cnt[i]/2;
		cnt[i]%=2;
	}
	int ret=0;
	for(int i=0;i<SIZE;i++) ret+=cnt[i];
	printf("%d\n",ret);
	return 0;
}