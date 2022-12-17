#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=3e5+5;
int n,h[maxn],dp[maxn];
vector<int>v;
vector<int>jump[maxn];
int main()
{
	n=getint();
	FOR(i,1,n)h[i]=getint();
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	FOR(i,1,n)/// 
	{
		while(!v.empty()&&h[v.back()]<h[i])v.pop_back();
		if(!v.empty())jump[i].push_back(v.back());
		v.push_back(i);
	}
	v.clear();
	FOR(i,1,n)/// 
	{
		while(!v.empty()&&h[v.back()]>h[i])v.pop_back();
		if(!v.empty())jump[i].push_back(v.back());
		v.push_back(i);
	}
	v.clear();
	for(int i=n;i>=1;--i)/// 
	{
		while(!v.empty()&&h[v.back()]<h[i])v.pop_back();
		if(!v.empty())jump[v.back()].push_back(i);
		v.push_back(i);
	}
	v.clear();
	for(int i=n;i>=1;--i)/// 
	{
		while(!v.empty()&&h[v.back()]>h[i])v.pop_back();
		if(!v.empty())jump[v.back()].push_back(i);
		v.push_back(i);
	}
	FOR(i,2,n)
	{
		FOR(j,0,(int)jump[i].size()-1)
		dp[i]=min(dp[i],dp[jump[i][j]]+1);
	}
	printf("%d\n",dp[n]);
	return 0;
}