#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n;
int A[SIZE];
ll dp[SIZE];
P pos[SIZE];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
	}
	int e=0;
	ll ret=0;
	for(int i=n-2;i>=0;i--)
	{
		while(0<e&&pos[e-1].second<=A[i]) e--;
		if(e==0) dp[i]=0;
		else
		{
			int to=lower_bound(pos,pos+e,P(-A[i],-1))-pos;
			int v=-pos[to].first;
			dp[i]=dp[v]+v-A[i];
		}
		dp[i]+=n-i-1;
		ret+=dp[i];
		pos[e++]=P(-i,A[i]);
	}
	printf("%lld\n",ret);
	return 0;
}