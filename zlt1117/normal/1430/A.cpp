#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
#define pb push_back
using namespace std;
inline int gi()
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
const int maxn=1005;
int T,n;
bool dp[1005];
int main()
{
	T=gi();
	dp[0]=1;
	FOR(i,1,1000)
	{
		if(i>=7)dp[i]|=dp[i-7];
		if(i>=5)dp[i]|=dp[i-5];
		if(i>=3)dp[i]|=dp[i-3];
	}
	while(T--)
	{
		n=gi();
		if(!dp[n])printf("-1\n");
		else
		{
			int cnt0=0,cnt1=0,cnt2=0;
			int now=n;
			while(now!=0)
			{
				if(now-3>=0&&dp[now-3])
				{
					cnt0++;
					now-=3;
				}
				else if(now-5>=0&&dp[now-5])
				{
					cnt1++;
					now-=5;
				}
				else if(now-7>=0&&dp[now-7])
				{
					cnt2++;
					now-=7;
				}
			}
			printf("%d %d %d\n",cnt0,cnt1,cnt2);
		}
	}
	return 0;
}