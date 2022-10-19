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
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 510
#define M 998244353 
using namespace std;

ll n,m,tmp[N][N],dp[N][N],qz[N],num[N],ans,er;

int main()
{
	ll i,j,k,p,q,t;
	er=(M+1)/2;
	cin>>n>>m;
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		memset(tmp,0,sizeof(tmp));
		for(j=(!!i);j<=i;j++)
		{
			for(k=0;k<=j;k++)
			{
				if(!dp[j][k]) continue;
				t=j+(!j);
				tmp[t][1]+=dp[j][k];
				tmp[t][1]%=M;
				if(k==j)
				{
					tmp[j+1][k+1]+=dp[j][k];
					tmp[j+1][k+1]%=M;
				}
				else
				{
					tmp[j][k+1]+=dp[j][k];
					tmp[j][k+1]%=M;
				}
			}
		}
		memcpy(dp,tmp,sizeof(dp));
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			num[i]=(num[i]+dp[i][j])%M;
		}
	}
//	for(i=1;i<=n;i++) cout<<num[i]<<" ";puts("");
	for(i=1;i<=n;i++)
	{
		qz[i]=(qz[i-1]+num[i])%M;
	}
	for(i=1;i<=n;i++)
	{
		ans=(ans+num[i]*qz[min((m-1)/i,n)]%M*er%M)%M;
	}
	cout<<ans;
}