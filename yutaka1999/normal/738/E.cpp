#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

int cnt[SIZE];

int main()
{
	int n,s;
	scanf("%d %d",&n,&s);s--;
	vector <int> vec;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(i==s)
		{
			if(a!=0) ret++;
		}
		else
		{
			cnt[a]++;
		}
	}
	int sum=1,nm=0;
	int pl=n-1;
	for(int i=1;i<n;i++)
	{
		if(cnt[i]==0) nm++;
		sum+=cnt[i];
		pl=min(pl,max(n-sum,nm));
	}
	printf("%d\n",ret+pl);
	return 0;
}