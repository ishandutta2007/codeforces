#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll dp[SIZE],cur[SIZE];
ll inv[SIZE];
int A[SIZE];

void make()
{
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
	}
}
ll solve(int n,int k,ll L)
{
	vector <int> vx;
	for(int i=0;i<n;i++) vx.push_back(A[i]);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++) A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
	dp[0]=1;
	ll ret=0;
	ll C=L/n;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<vx.size();j++) cur[j]=0;
		for(int j=1;j<vx.size();j++)
		{
			dp[j]+=dp[j-1];
			if(dp[j]>=MOD) dp[j]-=MOD;
		}
		for(int j=0;j<(int) (L%n);j++)
		{
			ret+=dp[A[j]];
			if(ret>=MOD) ret-=MOD;
		}
		if(i==C) break;
		for(int j=0;j<n;j++)
		{
			cur[A[j]]+=dp[A[j]];
			if(cur[A[j]]>=MOD) cur[A[j]]-=MOD;
		}
		ll sum=0;
		for(int j=0;j<vx.size();j++)
		{
			dp[j]=cur[j];
			sum+=dp[j];
			if(sum>=MOD) sum-=MOD;
		}
		ret+=(C-i)%MOD*sum%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	return ret;
}
int main()
{
	make();
	int n,k;
	ll L;
	scanf("%d %I64d %d",&n,&L,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	printf("%I64d\n",solve(n,k,L));
	return 0;
}