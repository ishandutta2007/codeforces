#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#define SIZE 305
#define MX 3000005

using namespace std;
typedef pair <int,int> P;

P dp[MX],cur[MX];
int L[SIZE],C[SIZE];

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&L[i]);
	for(int i=0;i<n;i++) scanf("%d",&C[i]);
	int sz=0;
	dp[sz++]=P(0,0);
	for(int i=0;i<n;i++)
	{
		int ns=0;
		for(int j=0;j<sz;j++)
		{
			P p=dp[j];
			cur[ns++]=p;
			cur[ns++]=P(gcd(p.first,L[i]),p.second+C[i]);
		}
		sort(cur,cur+ns);
		sz=0;
		for(int j=0;j<ns;)
		{
			dp[sz++]=cur[j];
			int s=cur[j].first;
			for(;j<ns&&cur[j].first==s;j++);
		}
	}
	for(int i=0;i<sz;i++)
	{
		if(dp[i].first==1)
		{
			printf("%d\n",dp[i].second);
			return 0;
		}
	}
	puts("-1");
	return 0;
}