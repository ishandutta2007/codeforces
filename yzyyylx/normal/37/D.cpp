#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#define ll long long
#define N 110
#define M 1000000007
using namespace std;

ll n,m,qz[N],dp[N][1010],x[N],y[N],ans=1,C[1010][1010];

inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		v>>=1;
		u=u*u%M;
	}
	return res;
}

int main()
{
	ll i,j,k;
	for(i=0;i<=1000;i++)
	{
		C[i][0]=C[i][i]=1;
		for(j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=M;
		}
	}
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&x[i]),qz[i]=qz[i-1]+x[i],m+=x[i];
	for(i=1;i<=n;i++) scanf("%lld",&y[i]);
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=qz[i];j++)
		{
			if(!dp[i][j]) continue;
			for(k=0;k<=y[i+1];k++)
			{
				dp[i+1][j+k]+=dp[i][j]*C[qz[i+1]-j][k]%M;
				dp[i+1][j+k]%=M;
			}
		}
	}
	for(i=1;i<=n;i++) ans=ans*C[qz[i]][x[i]]%M;
//	cout<<dp[n][m]<<" "<<ans<<endl;
	cout<<ans*dp[n][m]%M;
}