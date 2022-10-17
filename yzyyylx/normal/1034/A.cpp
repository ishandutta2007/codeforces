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
#define mp make_pair
#define fi first
#define se second
#define N 15001000
#define MN 100000
using namespace std;

ll n,num[N],cnt[N],ans,mx,g;
bool P[N],sa=1;

inline ll gcd(ll u,ll v)
{
	for(;u&&v&&u!=v;)
	{
		swap(u,v);
		u%=v;
	}
	return max(u,v);
}

int main()
{
	ll i,j,t,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(i==1) g=num[i];
		else g=gcd(g,num[i]);
		if(i>1) if(num[i]!=num[i-1]) sa=0;
	}
	if(sa)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		num[i]/=g;
		mx=max(mx,num[i]);
		cnt[num[i]]++;
	}
	for(i=2;i<=mx;i++)
	{
		if(P[i]) continue;
		p=0;
		for(j=i;j<=mx;j+=i)
		{
			P[j]=1;
			p+=cnt[j];
		}
		ans=max(ans,p);
	}
	cout<<n-ans;
}