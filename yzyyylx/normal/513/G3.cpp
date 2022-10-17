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
#define db double
#define N 110
#define CS 900
using namespace std;

int n,m,num[N];
db dp[N][N],tmp[N][N],ans,sum;

inline db calc(int u){return (db)(u)*(db)(u+1)/2;}

int main()
{
	int i,j,k,t,ii;
	cin>>n>>m;sum=n*(n+1)/2;
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	m=min(m,CS);
	for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) dp[i][j]=1;
	for(t=1;t<=m;t++)
	{
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) tmp[i][j]=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				tmp[i][j]=dp[i][j]*(calc(i-1)+calc(j-i-1)+calc(n-j))/sum;
				//i,j
				for(k=1-i;k+j<=n;k++)
					tmp[i][j]+=(1-dp[i+k][j+k])*min(min(i,i+k),n-max(j,j+k)+1)/sum;
				//i
				for(k=1-i;k<j-i;k++)
					tmp[i][j]+=dp[i+k][j]*min(min(i,i+k),j-max(i,i+k))/sum;
				//j
				for(k=i-j+1;k+j<=n;k++)
					tmp[i][j]+=dp[i][j+k]*min(min(j,j+k)-i,n-max(j,j+k)+1)/sum;
			}
		}
		memcpy(dp,tmp,sizeof(tmp));
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(num[i]>num[j]) ans+=dp[i][j];
			else ans+=1-dp[i][j];
		}
	}
	printf("%.10f",ans);
}