#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 500005
#define MX 10000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int dp[MX],rt[SIZE];
int dp2[MX],A[SIZE];
int cnt[MX],id[MX];
int nxt[MX],nd[MX];
bool pr[MX],ok[MX];
int sz;

void make()
{
	for(int i=1;i<MX;i++) nxt[i]=1;
	memset(pr,false,sizeof(pr));
	sz=0;
	nd[sz++]=1;
	for(int i=2;i<MX;i++)
	{
		if(!pr[i])
		{
			id[i]^=1;
			nxt[i]=i;
			for(int j=2*i;j<MX;j+=i)
			{
				pr[j]=true;
				id[j]^=1;
				nxt[j]*=i;
			}
		}
		if(nxt[i]==i)
		{
			nd[sz++]=i;
		}
	}
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	rt[0]=1;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		a=nxt[a];
		cnt[a]++;
		A[i]=a;
		rt[i+1]=rt[i]*2;
		if(rt[i+1]>=MOD) rt[i+1]-=MOD;
	}
	for(int i=sz-1;i>=0;i--)
	{
		int v=nd[i];
		dp[v]=0;
		int nm=0;
		for(int j=v;j<MX;j+=v)
		{
			nm+=cnt[j];
			dp[v]-=dp[j];
			if(dp[v]<0) dp[v]+=MOD;
		}
		dp[v]+=rt[nm]-1;
		if(dp[v]>=MOD) dp[v]-=MOD;
		if(id[v]==1) dp2[v]=rt[nm]-1;
		else
		{
			dp2[v]=MOD-(rt[nm]-1);
			if(dp2[v]>=MOD) dp2[v]-=MOD;
		}
	}
	for(int i=sz-1;i>=1;i--)
	{
		int v=nd[i];
		if(dp2[v]>0)
		{
			for(int j=v*2;j<MX;j+=v)
			{
				dp2[j]+=dp2[v];
				if(dp2[j]>=MOD) dp2[j]-=MOD;
			}
		}
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		//int del=dp2[A[i]]+1;
		//del Igcd>1A~KA
		//K+(iOgcd=1)=(igcd=1)A(iOgcd=1)+(igcd=1)=dp[1]A(igcd=1)=rt[n-1]-del/2
		//AK=(igcd=1)-(iOgcd=1)=2*(igcd=1)-dp[1]=rt[n]-del-dp[1]
		int sum=rt[n]-dp2[A[i]]-1;
		if(sum<0) sum+=MOD;
		sum-=dp[1];
		if(sum<0) sum+=MOD;
		//if(cnt[i]>0) printf("%d : %lld %lld\n",i,del,sum);
		ret+=sum;
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}